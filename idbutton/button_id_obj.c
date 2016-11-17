#include <stdio.h>
#include <openbmc_intf.h>
#include <gpio.h>
#include <openbmc.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <systemd/sd-bus.h>

/* ------------------------------------------------------------------------- */
static const gchar* dbus_object_path = "/org/openbmc/buttons";
static const gchar* instance_name = "id0";
static const gchar* dbus_name = "org.openbmc.buttons.id";
static const int LONG_PRESS_SECONDS = 3;
static GDBusObjectManagerServer *manager = NULL;
const char *power_ctrl = "brightness";

//This object will use these GPIOs
GPIO gpio_button = (GPIO){ "IDBTN" };

int
write_to_led_uid(const char *name, const char *ctrl_file, const char *value)
{
	/* Generic error reporter. */
	int rc = -1;

	/* To get /sys/class/leds/<name>/<control file> */
	char led_path[128] = {0};

	int len = 0;
	len = snprintf(led_path, sizeof(led_path),
			"/sys/class/leds/%s/%s",name, ctrl_file);
	if(len >= sizeof(led_path))
	{
		return rc;
	}

	FILE *fp = fopen(led_path,"w");
	if(fp == NULL)
	{
		return rc;
	}

	rc = fwrite(value, strlen(value), 1, fp);

	fclose(fp);

	/* When we get here, rc would be what it was from writing to the file */
	return (rc == 1) ? 0 : -1;
}

static gboolean
on_button_interrupt( GIOChannel *channel,
		GIOCondition condition,
		gpointer user_data )
{
	GError *error = 0;
	gsize bytes_read = 0;
	gchar buf[2];
    static int light_on = 0;
	buf[1] = '\0';
    g_io_channel_seek_position( channel, 0, G_SEEK_SET, 0 );
	g_io_channel_read_chars(channel,
			buf, 1,
			&bytes_read,
			&error ); 

	if(gpio_button.irq_inited)
	{
		if(buf[0] == '0')
		{
		    //button pressed
		    printf("UID button pressed\n");
            int rc = -1;
            if (light_on == 0)
            {
                /*
	                     * Before doing anything, need to turn off the blinking
	                     * if there is one in progress by writing 'none' to trigger
	                     */
                rc = write_to_led_uid("identify", power_ctrl, "0");
	            if(rc < 0)
	            {
		            fprintf(stderr,"Error disabling blink.\n");
		            return TRUE;
	            }

                /*
	                    * Open the brightness file and write corresponding values.
	                    */
                rc = write_to_led_uid("identify", power_ctrl, "255");
	            if(rc < 0)
	            {
		            fprintf(stderr,"Error driving LED.\n");
	            }
                light_on = 1;
            }
            else
            {
                rc = write_to_led_uid("identify", power_ctrl, "0");
	            if(rc < 0)
	            {
		            fprintf(stderr,"Error disabling blink.\n");
		            return TRUE;
	            }
                light_on = 0;
            }
            
		}
		else
		{
		    //button released
            printf("UID button released\n");
		}
	}
	else { gpio_button.irq_inited = true; }

	return TRUE;
}

static void
on_bus_acquired(GDBusConnection *connection,
		const gchar *name,
		gpointer user_data)
{
	ObjectSkeleton *object;
	//g_print ("Acquired a message bus connection: %s\n",name);
	manager = g_dbus_object_manager_server_new(dbus_object_path);
	gchar *s;
	s = g_strdup_printf("%s/%s",dbus_object_path,instance_name);
	object = object_skeleton_new(s);
	g_free(s);

	Button* button = button_skeleton_new();
	object_skeleton_set_button(object, button);
	g_object_unref(button);

	/* Export the object (@manager takes its own reference to @object) */
	g_dbus_object_manager_server_set_connection(manager, connection);
	g_dbus_object_manager_server_export(manager, G_DBUS_OBJECT_SKELETON(object));
	g_object_unref(object);

	// get gpio device paths
	int rc = GPIO_OK;
	do {
		rc = gpio_init(connection,&gpio_button);
		if(rc != GPIO_OK) { break; }
		rc = gpio_open_interrupt(&gpio_button,on_button_interrupt,object);
		if(rc != GPIO_OK) { break; }
	} while(0);
	if(rc != GPIO_OK)
	{
		printf("ERROR PowerButton: GPIO setup (rc=%d)\n",rc);
	}
}

static void
on_name_acquired(GDBusConnection *connection,
		const gchar *name,
		gpointer user_data)
{
}

static void
on_name_lost(GDBusConnection *connection,
		const gchar *name,
		gpointer user_data)
{
}

gint
main(gint argc, gchar *argv[])
{
	GMainLoop *loop;

	cmdline cmd;
	cmd.argc = argc;
	cmd.argv = argv;

	guint id;
	loop = g_main_loop_new(NULL, FALSE);

	id = g_bus_own_name(DBUS_TYPE,
			dbus_name,
			G_BUS_NAME_OWNER_FLAGS_ALLOW_REPLACEMENT |
			G_BUS_NAME_OWNER_FLAGS_REPLACE,
			on_bus_acquired,
			on_name_acquired,
			on_name_lost,
			&cmd,
			NULL);

	g_main_loop_run(loop);

	g_bus_unown_name(id);
	g_main_loop_unref(loop);
	return 0;
}
