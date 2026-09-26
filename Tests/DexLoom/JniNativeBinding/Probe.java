/* Test-only class loaded by the pinned API19 CLEAN image.
   Native methods are declared here so libdvm RegisterNatives sees the real
   Dalvik method flags. plain() is ordinary bytecode and must stay that way
   when registration is rejected. */
public class Probe {
    public static native int value();
    public static native int value(int x);
    public static native int fast();
    public native int inst();
    public static synchronized native int synced();
    public static int plain() { return 7; }

    public static void main(String[] args) {
        System.load(args[0]);
    }
}
