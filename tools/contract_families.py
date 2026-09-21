#!/usr/bin/env python3
"""Frozen public-contract granularity for the architecture falsification experiment.

A public contract family is one guest-visible compatibility behavior unit with a
single API19 source owner that can be described and verified by one focused
contract. Many classes and methods may expose the same family; the family is
counted once. This table is the granularity freeze: it must not be re-cut after
dynamic results are observed, and its fingerprint is recorded in every artifact
that reports convergence numbers.

`scope` records how the family relates to the AGR product scope:
  CORE      - reachable on a normal local single-player gameplay path
  SHELL     - application chrome (menus, settings, dialogs) that may gate entry
              to gameplay but is not gameplay itself
  OPTIONAL  - third-party/online/device capability that a local game can lose
              without losing core gameplay
  EXTERNAL  - depends on a system or network authority outside one app process
"""
from __future__ import annotations

import hashlib
import json
import pathlib

# family -> (scope, API19 owner hint)
FAMILIES: dict[str, tuple[str, str]] = {
    "app.activity_lifecycle": ("CORE", "android.app.ActivityThread/Activity/Instrumentation"),
    "app.application_lifecycle": ("CORE", "android.app.LoadedApk/Application"),
    "app.native_activity": ("CORE", "frameworks/base/native/android + android.app.NativeActivity"),
    "app.context": ("CORE", "android.app.ContextImpl"),
    "app.intent": ("CORE", "android.content.Intent/ActivityManagerService startActivity"),
    "app.service_lifecycle": ("SHELL", "android.app.ActivityThread handleCreateService"),
    "app.broadcast": ("SHELL", "android.app.LoadedApk$ReceiverDispatcher"),
    "app.package_info": ("CORE", "android.content.pm.PackageManager"),
    "app.uri": ("CORE", "android.net.Uri (pure library)"),
    "app.wallpaper_service": ("OPTIONAL", "android.service.wallpaper.WallpaperService"),
    "resources.asset_access": ("CORE", "android.content.res.Resources/AssetManager + androidfw"),
    "storage.shared_preferences": ("CORE", "android.app.SharedPreferencesImpl"),
    "storage.filesystem": ("CORE", "android.os.Environment/ContextImpl file paths"),
    "storage.content_provider": ("SHELL", "android.content.ContentResolver/ActivityThread provider"),
    "storage.sqlite": ("SHELL", "android.database.sqlite + external/sqlite"),
    "view.hierarchy": ("CORE", "android.view.View/ViewGroup measure-layout-draw"),
    "window.session": ("CORE", "android.view.WindowManagerGlobal/ViewRootImpl/IWindowSession"),
    "window.display_metrics": ("CORE", "android.view.Display/DisplayManagerGlobal"),
    "graphics.surface_lifecycle": ("CORE", "android.view.SurfaceView/Surface + SurfaceFlinger client"),
    "graphics.glsurfaceview": ("CORE", "android.opengl.GLSurfaceView"),
    "graphics.egl_java": ("CORE", "com.google.android.gles_jni.EGLImpl"),
    "graphics.gles_java": ("CORE", "android.opengl.GLES* JNI to libGLESv*"),
    "graphics.egl_native": ("CORE", "frameworks/native/opengl/libs EGL"),
    "graphics.gles_native": ("CORE", "frameworks/native/opengl/libs GLESv1_CM/GLESv2"),
    "graphics.canvas_2d": ("CORE", "android.graphics.Canvas/Paint + Skia"),
    "graphics.bitmap": ("CORE", "android.graphics.Bitmap/BitmapFactory + Skia"),
    "graphics.bitmap_native": ("CORE", "libjnigraphics AndroidBitmap_*"),
    "graphics.drawable": ("SHELL", "android.graphics.drawable"),
    "text.layout": ("SHELL", "android.text.StaticLayout/TextPaint"),
    "ui.toolkit": ("SHELL", "android.widget.*"),
    "ui.dialog": ("SHELL", "android.app.Dialog/AlertDialog"),
    "ui.menu": ("SHELL", "com.android.internal.view.menu"),
    "ui.preferences": ("SHELL", "android.preference.*"),
    "ui.animation": ("SHELL", "android.view.animation / android.animation"),
    "ui.accessibility": ("OPTIONAL", "android.view.accessibility + AccessibilityManagerService"),
    "ui.webview": ("OPTIONAL", "android.webkit.WebView + WebViewCore"),
    "ui.support_compat": ("SHELL", "bundled android.support.v4 (app code, not platform)"),
    "input.motion_event": ("CORE", "android.view.MotionEvent/InputEventReceiver/InputQueue"),
    "input.key_event": ("CORE", "android.view.KeyEvent/KeyCharacterMap"),
    "input.ime": ("SHELL", "android.view.inputmethod.InputMethodManager + IMMS"),
    "concurrency.handler_looper": ("CORE", "android.os.Handler/Looper/MessageQueue"),
    "concurrency.async_task": ("CORE", "android.os.AsyncTask"),
    "ipc.parcel_binder": ("CORE", "android.os.Parcel/Binder (marshalling surface)"),
    "ipc.local_socket": ("OPTIONAL", "android.net.LocalSocket"),
    "audio.soundpool": ("CORE", "android.media.SoundPool + AudioFlinger client"),
    "audio.audiotrack": ("CORE", "android.media.AudioTrack + AudioFlinger client"),
    "audio.audiorecord": ("OPTIONAL", "android.media.AudioRecord"),
    "audio.mediaplayer": ("CORE", "android.media.MediaPlayer + StagefrightPlayer"),
    "audio.policy": ("CORE", "android.media.AudioManager + AudioService"),
    "audio.opensles": ("CORE", "frameworks/wilhelm OpenSL ES"),
    "audio.system_media": ("OPTIONAL", "RingtoneManager/MediaScanner/RemoteControlClient"),
    "sensor.event_stream": ("CORE", "android.hardware.SensorManager + SensorService"),
    "system.vibrator": ("CORE", "android.os.Vibrator + VibratorService"),
    "system.wakelock": ("CORE", "android.os.PowerManager + PowerManagerService"),
    "system.clock": ("CORE", "android.os.SystemClock"),
    "system.build_info": ("CORE", "android.os.Build"),
    "system.process_info": ("CORE", "android.os.Process/Debug"),
    "system.log": ("CORE", "android.util.Log + liblog"),
    "system.settings": ("SHELL", "android.provider.Settings + SettingsProvider"),
    "system.clipboard": ("SHELL", "android.content.ClipboardManager + ClipboardService"),
    "system.notification": ("OPTIONAL", "android.app.NotificationManager + NMS"),
    "system.alarm": ("OPTIONAL", "android.app.AlarmManager + AlarmManagerService"),
    "system.search": ("OPTIONAL", "android.app.SearchManager"),
    "system.backup": ("OPTIONAL", "android.app.backup + BackupManagerService"),
    "system.appwidget": ("EXTERNAL", "AppWidgetService + host process"),
    "system.print": ("OPTIONAL", "android.print + PrintSpooler process"),
    "system.telephony": ("OPTIONAL", "android.telephony + TelephonyRegistry"),
    "system.display_input_service": ("OPTIONAL", "DisplayManager/InputManager"),
    "system.misc_util": ("CORE", "android.os small utility types"),
    "net.connectivity": ("OPTIONAL", "android.net.ConnectivityManager + CS"),
    "net.wifi": ("OPTIONAL", "android.net.wifi.WifiManager + WifiService"),
    "hardware.camera": ("OPTIONAL", "android.hardware.Camera + CameraService"),
    "util.library": ("CORE", "android.util pure library types"),
    "runtime.dex_classloader": ("CORE", "dalvik.system.DexClassLoader"),
    "bionic.libc": ("CORE", "bionic libc/libm/libdl"),
    "native.log": ("CORE", "liblog"),
    "native.zlib": ("CORE", "external/zlib"),
    "native.stlport_gnustl": ("CORE", "GNU libstdc++ / STLport runtime"),
    "native.app_glue": ("CORE", "android_native_app_glue + libandroid"),
    "native.asset_manager": ("CORE", "AAssetManager_* in libandroid"),
    "native.native_window": ("CORE", "ANativeWindow_* in libandroid"),
    "native.input_queue": ("CORE", "AInputQueue_* in libandroid"),
    "native.looper": ("CORE", "ALooper_* in libandroid"),
    "native.sensor": ("CORE", "ASensorManager_* in libandroid"),
    "native.configuration": ("CORE", "AConfiguration_* in libandroid"),
    "native.openmaxal": ("OPTIONAL", "libOpenMAXAL"),
    "jni.bridge": ("CORE", "dalvik JNI invocation and registration"),
}

# Exact class name -> family. Checked before prefix rules.
EXACT: dict[str, str] = {
    "android.app.Activity": "app.activity_lifecycle",
    "android.app.ActivityManager": "app.activity_lifecycle",
    "android.app.ActivityOptions": "app.activity_lifecycle",
    "android.app.Application": "app.application_lifecycle",
    "android.app.NativeActivity": "app.native_activity",
    "android.app.Service": "app.service_lifecycle",
    "android.app.AlarmManager": "system.alarm",
    "android.app.SearchManager": "system.search",
    "android.app.SearchableInfo": "system.search",
    "android.app.PendingIntent": "system.notification",
    "android.content.Context": "app.context",
    "android.content.ContextWrapper": "app.context",
    "android.content.Intent": "app.intent",
    "android.content.IntentFilter": "app.intent",
    "android.content.IntentFilter$AuthorityEntry": "app.intent",
    "android.content.ComponentName": "app.intent",
    "android.content.ActivityNotFoundException": "app.intent",
    "android.content.IntentSender$SendIntentException": "app.intent",
    "android.content.BroadcastReceiver": "app.broadcast",
    "android.content.ClipData": "system.clipboard",
    "android.content.ClipData$Item": "system.clipboard",
    "android.content.ClipboardManager": "system.clipboard",
    "android.text.ClipboardManager": "system.clipboard",
    "android.content.ContentProvider": "storage.content_provider",
    "android.content.ContentResolver": "storage.content_provider",
    "android.content.ContentUris": "storage.content_provider",
    "android.content.ContentValues": "storage.content_provider",
    "android.content.UriMatcher": "storage.content_provider",
    "android.net.Uri": "app.uri",
    "android.net.Uri$Builder": "app.uri",
    "android.net.ConnectivityManager": "net.connectivity",
    "android.net.NetworkInfo": "net.connectivity",
    "android.net.NetworkInfo$State": "net.connectivity",
    "android.net.Proxy": "net.connectivity",
    "android.net.TrafficStats": "net.connectivity",
    "android.net.DhcpInfo": "net.wifi",
    "android.net.LocalSocket": "ipc.local_socket",
    "android.net.LocalServerSocket": "ipc.local_socket",
    "android.os.SystemClock": "system.clock",
    "android.os.Environment": "storage.filesystem",
    "android.os.StatFs": "storage.filesystem",
    "android.os.ParcelFileDescriptor": "storage.filesystem",
    "android.os.AsyncTask": "concurrency.async_task",
    "android.os.Vibrator": "system.vibrator",
    "android.os.Process": "system.process_info",
    "android.os.Debug": "system.process_info",
    "android.os.CancellationSignal": "system.misc_util",
    "android.os.PatternMatcher": "system.misc_util",
    "android.media.SoundPool": "audio.soundpool",
    "android.media.AudioTrack": "audio.audiotrack",
    "android.media.AudioRecord": "audio.audiorecord",
    "android.media.MediaPlayer": "audio.mediaplayer",
    "android.media.AudioManager": "audio.policy",
    "android.hardware.Camera": "hardware.camera",
    "android.hardware.Camera$Parameters": "hardware.camera",
    "android.hardware.Camera$Size": "hardware.camera",
    "android.view.Surface": "graphics.surface_lifecycle",
    "android.view.SurfaceView": "graphics.surface_lifecycle",
    "android.view.SurfaceHolder": "graphics.surface_lifecycle",
    "android.view.SurfaceHolder$Callback": "graphics.surface_lifecycle",
    "android.view.TextureView": "graphics.surface_lifecycle",
    "android.view.Window": "window.session",
    "android.view.Window$Callback": "window.session",
    "android.view.WindowManager": "window.session",
    "android.view.WindowManager$LayoutParams": "window.session",
    "android.view.Display": "window.display_metrics",
    "android.util.DisplayMetrics": "window.display_metrics",
    "android.view.MotionEvent": "input.motion_event",
    "android.view.InputDevice": "input.motion_event",
    "android.view.InputDevice$MotionRange": "input.motion_event",
    "android.view.VelocityTracker": "input.motion_event",
    "android.view.GestureDetector": "input.motion_event",
    "android.view.GestureDetector$OnGestureListener": "input.motion_event",
    "android.view.GestureDetector$OnDoubleTapListener": "input.motion_event",
    "android.view.GestureDetector$SimpleOnGestureListener": "input.motion_event",
    "android.view.ScaleGestureDetector": "input.motion_event",
    "android.view.OrientationEventListener": "sensor.event_stream",
    "android.view.SoundEffectConstants": "audio.policy",
    "android.view.KeyEvent": "input.key_event",
    "android.view.KeyEvent$DispatcherState": "input.key_event",
    "android.view.KeyCharacterMap": "input.key_event",
    "android.view.KeyCharacterMap$KeyData": "input.key_event",
    "android.util.Log": "system.log",
    "android.util.EventLog": "system.log",
    "android.support.v4": "ui.support_compat",
    "dalvik.system.DexClassLoader": "runtime.dex_classloader",
    "android.opengl.GLSurfaceView": "graphics.glsurfaceview",
    "android.opengl.GLSurfaceView$Renderer": "graphics.glsurfaceview",
    "android.opengl.GLSurfaceView$EGLConfigChooser": "graphics.glsurfaceview",
}

# Ordered prefix rules; first match wins.
PREFIXES: tuple[tuple[str, str], ...] = (
    ("android.app.Notification", "system.notification"),
    ("android.app.backup", "system.backup"),
    ("android.app.Dialog", "ui.dialog"),
    ("android.app.AlertDialog", "ui.dialog"),
    ("android.app.ProgressDialog", "ui.dialog"),
    ("android.app.ActionBar", "ui.toolkit"),
    ("android.app.ListActivity", "app.activity_lifecycle"),
    ("android.app.TabActivity", "app.activity_lifecycle"),
    ("android.app.ExpandableListActivity", "app.activity_lifecycle"),
    ("android.appwidget", "system.appwidget"),
    ("android.accessibilityservice", "ui.accessibility"),
    ("android.animation", "ui.animation"),
    ("android.content.SharedPreferences", "storage.shared_preferences"),
    ("android.content.DialogInterface", "ui.dialog"),
    ("android.content.res", "resources.asset_access"),
    ("android.content.pm", "app.package_info"),
    ("android.database.sqlite", "storage.sqlite"),
    ("android.database", "storage.content_provider"),
    ("android.graphics.Bitmap", "graphics.bitmap"),
    ("android.graphics.ImageFormat", "graphics.bitmap"),
    ("android.graphics.drawable", "graphics.drawable"),
    ("android.graphics.pdf", "system.print"),
    ("android.graphics", "graphics.canvas_2d"),
    ("android.print", "system.print"),
    ("android.hardware.Sensor", "sensor.event_stream"),
    ("android.hardware.display", "system.display_input_service"),
    ("android.hardware.input", "system.display_input_service"),
    ("android.hardware.usb", "system.display_input_service"),
    ("android.inputmethodservice", "input.ime"),
    ("android.media.Ringtone", "audio.system_media"),
    ("android.media.MediaScannerConnection", "audio.system_media"),
    ("android.media.RemoteControlClient", "audio.system_media"),
    ("android.media.MediaCodec", "audio.system_media"),
    ("android.net.wifi", "net.wifi"),
    ("android.opengl", "graphics.gles_java"),
    ("javax.microedition.khronos.egl", "graphics.egl_java"),
    ("javax.microedition.khronos.opengles", "graphics.gles_java"),
    ("javax.microedition.khronos", "graphics.gles_java"),
    ("android.os.Handler", "concurrency.handler_looper"),
    ("android.os.Looper", "concurrency.handler_looper"),
    ("android.os.Message", "concurrency.handler_looper"),
    ("android.os.Build", "system.build_info"),
    ("android.os.PowerManager", "system.wakelock"),
    ("android.os.Bundle", "ipc.parcel_binder"),
    ("android.os.Parcel", "ipc.parcel_binder"),
    ("android.os.Binder", "ipc.parcel_binder"),
    ("android.os.IBinder", "ipc.parcel_binder"),
    ("android.os.IInterface", "ipc.parcel_binder"),
    ("android.os.RemoteException", "ipc.parcel_binder"),
    ("android.os.DeadObjectException", "ipc.parcel_binder"),
    ("android.os.ResultReceiver", "ipc.parcel_binder"),
    ("android.preference", "ui.preferences"),
    ("android.provider.Settings", "system.settings"),
    ("android.provider", "storage.content_provider"),
    ("android.service.wallpaper", "app.wallpaper_service"),
    ("android.service.dreams", "app.wallpaper_service"),
    ("android.telephony", "system.telephony"),
    ("android.text", "text.layout"),
    ("android.util.Sparse", "util.library"),
    ("android.util.Pair", "util.library"),
    ("android.util.Base64", "util.library"),
    ("android.util.FloatMath", "util.library"),
    ("android.util.Xml", "util.library"),
    ("android.util.AndroidRuntimeException", "util.library"),
    ("android.util.AttributeSet", "view.hierarchy"),
    ("android.util.StateSet", "view.hierarchy"),
    ("android.util.TypedValue", "view.hierarchy"),
    ("android.view.accessibility", "ui.accessibility"),
    ("android.view.animation", "ui.animation"),
    ("android.view.inputmethod", "input.ime"),
    ("android.view.Menu", "ui.menu"),
    ("android.view.SubMenu", "ui.menu"),
    ("android.view.ContextMenu", "ui.menu"),
    ("android.view.ActionMode", "ui.menu"),
    ("android.view.ActionProvider", "ui.menu"),
    ("android.webkit", "ui.webview"),
    ("android.widget", "ui.toolkit"),
    ("android.view", "view.hierarchy"),
    ("android.os", "system.misc_util"),
    ("android.app", "app.activity_lifecycle"),
    ("android.content", "app.context"),
    ("android.net", "net.connectivity"),
    ("android.media", "audio.policy"),
    ("android.hardware", "system.display_input_service"),
    ("android.util", "util.library"),
    ("dalvik.system", "runtime.dex_classloader"),
)

NATIVE_LIBRARY_FAMILIES: dict[str, tuple[str, ...]] = {
    "libc.so": ("bionic.libc",),
    "libm.so": ("bionic.libc",),
    "libdl.so": ("bionic.libc",),
    "liblog.so": ("native.log",),
    "libz.so": ("native.zlib",),
    "libstdc++.so": ("native.stlport_gnustl",),
    "libgnustl_shared.so": ("native.stlport_gnustl",),
    "libstlport_shared.so": ("native.stlport_gnustl",),
    "libEGL.so": ("graphics.egl_native",),
    "libGLESv1_CM.so": ("graphics.gles_native",),
    "libGLESv2.so": ("graphics.gles_native",),
    "libGLESv3.so": ("graphics.gles_native",),
    "libOpenSLES.so": ("audio.opensles",),
    "libOpenMAXAL.so": ("native.openmaxal",),
    "libjnigraphics.so": ("graphics.bitmap_native",),
}

NATIVE_IMPORT_FAMILIES: tuple[tuple[str, str], ...] = (
    ("AAssetManager_", "native.asset_manager"),
    ("AAsset_", "native.asset_manager"),
    ("AAssetDir_", "native.asset_manager"),
    ("ANativeWindow_", "native.native_window"),
    ("ANativeActivity_", "native.app_glue"),
    ("AInputQueue_", "native.input_queue"),
    ("AInputEvent_", "native.input_queue"),
    ("AMotionEvent_", "native.input_queue"),
    ("AKeyEvent_", "native.input_queue"),
    ("ALooper_", "native.looper"),
    ("ASensor", "native.sensor"),
    ("AConfiguration_", "native.configuration"),
    ("AndroidBitmap_", "graphics.bitmap_native"),
    ("SL_", "audio.opensles"),
    ("slCreateEngine", "audio.opensles"),
)


def family_for_class(name: str) -> str | None:
    if name in EXACT:
        return EXACT[name]
    base = name.split("$", 1)[0]
    if base in EXACT:
        return EXACT[base]
    for prefix, family in PREFIXES:
        if name == prefix or name.startswith(prefix):
            return family
    return None


def families_for_native(needed: list[str], imports: list[str]) -> set[str]:
    result: set[str] = set()
    for library in needed:
        result.update(NATIVE_LIBRARY_FAMILIES.get(library, ()))
    for symbol in imports:
        for prefix, family in NATIVE_IMPORT_FAMILIES:
            if symbol.startswith(prefix):
                result.add(family)
                break
    return result


def fingerprint() -> str:
    return hashlib.sha256(pathlib.Path(__file__).read_bytes()).hexdigest()


def table() -> dict:
    return {
        "granularity_fingerprint": fingerprint(),
        "family_count": len(FAMILIES),
        "families": {
            name: {"scope": scope, "api19_owner": owner}
            for name, (scope, owner) in sorted(FAMILIES.items())
        },
    }


if __name__ == "__main__":
    print(json.dumps(table(), indent=2))
