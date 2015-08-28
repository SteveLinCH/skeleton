/*
 * Generated by gdbus-codegen 2.40.2. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __INTERFACES_LED_H__
#define __INTERFACES_LED_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.openbmc.Led */

#define TYPE_LED (led_get_type ())
#define LED(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_LED, Led))
#define IS_LED(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_LED))
#define LED_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_LED, LedIface))

struct _Led;
typedef struct _Led Led;
typedef struct _LedIface LedIface;

struct _LedIface
{
  GTypeInterface parent_iface;


  gboolean (*handle_set_blink_fast) (
    Led *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_set_blink_slow) (
    Led *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_set_off) (
    Led *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_set_on) (
    Led *object,
    GDBusMethodInvocation *invocation);

  gint  (*get_color) (Led *object);

  const gchar * (*get_function) (Led *object);

};

GType led_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *led_interface_info (void);
guint led_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void led_complete_set_on (
    Led *object,
    GDBusMethodInvocation *invocation);

void led_complete_set_off (
    Led *object,
    GDBusMethodInvocation *invocation);

void led_complete_set_blink_slow (
    Led *object,
    GDBusMethodInvocation *invocation);

void led_complete_set_blink_fast (
    Led *object,
    GDBusMethodInvocation *invocation);



/* D-Bus method calls: */
void led_call_set_on (
    Led *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean led_call_set_on_finish (
    Led *proxy,
    GAsyncResult *res,
    GError **error);

gboolean led_call_set_on_sync (
    Led *proxy,
    GCancellable *cancellable,
    GError **error);

void led_call_set_off (
    Led *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean led_call_set_off_finish (
    Led *proxy,
    GAsyncResult *res,
    GError **error);

gboolean led_call_set_off_sync (
    Led *proxy,
    GCancellable *cancellable,
    GError **error);

void led_call_set_blink_slow (
    Led *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean led_call_set_blink_slow_finish (
    Led *proxy,
    GAsyncResult *res,
    GError **error);

gboolean led_call_set_blink_slow_sync (
    Led *proxy,
    GCancellable *cancellable,
    GError **error);

void led_call_set_blink_fast (
    Led *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean led_call_set_blink_fast_finish (
    Led *proxy,
    GAsyncResult *res,
    GError **error);

gboolean led_call_set_blink_fast_sync (
    Led *proxy,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
gint led_get_color (Led *object);
void led_set_color (Led *object, gint value);

const gchar *led_get_function (Led *object);
gchar *led_dup_function (Led *object);
void led_set_function (Led *object, const gchar *value);


/* ---- */

#define TYPE_LED_PROXY (led_proxy_get_type ())
#define LED_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_LED_PROXY, LedProxy))
#define LED_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_LED_PROXY, LedProxyClass))
#define LED_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_LED_PROXY, LedProxyClass))
#define IS_LED_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_LED_PROXY))
#define IS_LED_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_LED_PROXY))

typedef struct _LedProxy LedProxy;
typedef struct _LedProxyClass LedProxyClass;
typedef struct _LedProxyPrivate LedProxyPrivate;

struct _LedProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  LedProxyPrivate *priv;
};

struct _LedProxyClass
{
  GDBusProxyClass parent_class;
};

GType led_proxy_get_type (void) G_GNUC_CONST;

void led_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
Led *led_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
Led *led_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void led_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
Led *led_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
Led *led_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_LED_SKELETON (led_skeleton_get_type ())
#define LED_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_LED_SKELETON, LedSkeleton))
#define LED_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_LED_SKELETON, LedSkeletonClass))
#define LED_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_LED_SKELETON, LedSkeletonClass))
#define IS_LED_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_LED_SKELETON))
#define IS_LED_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_LED_SKELETON))

typedef struct _LedSkeleton LedSkeleton;
typedef struct _LedSkeletonClass LedSkeletonClass;
typedef struct _LedSkeletonPrivate LedSkeletonPrivate;

struct _LedSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  LedSkeletonPrivate *priv;
};

struct _LedSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType led_skeleton_get_type (void) G_GNUC_CONST;

Led *led_skeleton_new (void);


/* ---- */

#define TYPE_OBJECT (object_get_type ())
#define OBJECT(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_OBJECT, Object))
#define IS_OBJECT(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_OBJECT))
#define OBJECT_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_OBJECT, Object))

struct _Object;
typedef struct _Object Object;
typedef struct _ObjectIface ObjectIface;

struct _ObjectIface
{
  GTypeInterface parent_iface;
};

GType object_get_type (void) G_GNUC_CONST;

Led *object_get_led (Object *object);
Led *object_peek_led (Object *object);

#define TYPE_OBJECT_PROXY (object_proxy_get_type ())
#define OBJECT_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_OBJECT_PROXY, ObjectProxy))
#define OBJECT_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_OBJECT_PROXY, ObjectProxyClass))
#define OBJECT_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_OBJECT_PROXY, ObjectProxyClass))
#define IS_OBJECT_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_OBJECT_PROXY))
#define IS_OBJECT_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_OBJECT_PROXY))

typedef struct _ObjectProxy ObjectProxy;
typedef struct _ObjectProxyClass ObjectProxyClass;
typedef struct _ObjectProxyPrivate ObjectProxyPrivate;

struct _ObjectProxy
{
  /*< private >*/
  GDBusObjectProxy parent_instance;
  ObjectProxyPrivate *priv;
};

struct _ObjectProxyClass
{
  GDBusObjectProxyClass parent_class;
};

GType object_proxy_get_type (void) G_GNUC_CONST;
ObjectProxy *object_proxy_new (GDBusConnection *connection, const gchar *object_path);

#define TYPE_OBJECT_SKELETON (object_skeleton_get_type ())
#define OBJECT_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_OBJECT_SKELETON, ObjectSkeleton))
#define OBJECT_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_OBJECT_SKELETON, ObjectSkeletonClass))
#define OBJECT_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_OBJECT_SKELETON, ObjectSkeletonClass))
#define IS_OBJECT_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_OBJECT_SKELETON))
#define IS_OBJECT_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_OBJECT_SKELETON))

typedef struct _ObjectSkeleton ObjectSkeleton;
typedef struct _ObjectSkeletonClass ObjectSkeletonClass;
typedef struct _ObjectSkeletonPrivate ObjectSkeletonPrivate;

struct _ObjectSkeleton
{
  /*< private >*/
  GDBusObjectSkeleton parent_instance;
  ObjectSkeletonPrivate *priv;
};

struct _ObjectSkeletonClass
{
  GDBusObjectSkeletonClass parent_class;
};

GType object_skeleton_get_type (void) G_GNUC_CONST;
ObjectSkeleton *object_skeleton_new (const gchar *object_path);
void object_skeleton_set_led (ObjectSkeleton *object, Led *interface_);

/* ---- */

#define TYPE_OBJECT_MANAGER_CLIENT (object_manager_client_get_type ())
#define OBJECT_MANAGER_CLIENT(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_OBJECT_MANAGER_CLIENT, ObjectManagerClient))
#define OBJECT_MANAGER_CLIENT_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_OBJECT_MANAGER_CLIENT, ObjectManagerClientClass))
#define OBJECT_MANAGER_CLIENT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_OBJECT_MANAGER_CLIENT, ObjectManagerClientClass))
#define IS_OBJECT_MANAGER_CLIENT(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_OBJECT_MANAGER_CLIENT))
#define IS_OBJECT_MANAGER_CLIENT_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_OBJECT_MANAGER_CLIENT))

typedef struct _ObjectManagerClient ObjectManagerClient;
typedef struct _ObjectManagerClientClass ObjectManagerClientClass;
typedef struct _ObjectManagerClientPrivate ObjectManagerClientPrivate;

struct _ObjectManagerClient
{
  /*< private >*/
  GDBusObjectManagerClient parent_instance;
  ObjectManagerClientPrivate *priv;
};

struct _ObjectManagerClientClass
{
  GDBusObjectManagerClientClass parent_class;
};

GType object_manager_client_get_type (void) G_GNUC_CONST;

GType object_manager_client_get_proxy_type (GDBusObjectManagerClient *manager, const gchar *object_path, const gchar *interface_name, gpointer user_data);

void object_manager_client_new (
    GDBusConnection        *connection,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GAsyncReadyCallback     callback,
    gpointer                user_data);
GDBusObjectManager *object_manager_client_new_finish (
    GAsyncResult        *res,
    GError             **error);
GDBusObjectManager *object_manager_client_new_sync (
    GDBusConnection        *connection,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GError                **error);

void object_manager_client_new_for_bus (
    GBusType                bus_type,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GAsyncReadyCallback     callback,
    gpointer                user_data);
GDBusObjectManager *object_manager_client_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
GDBusObjectManager *object_manager_client_new_for_bus_sync (
    GBusType                bus_type,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GError                **error);


G_END_DECLS

#endif /* __INTERFACES_LED_H__ */