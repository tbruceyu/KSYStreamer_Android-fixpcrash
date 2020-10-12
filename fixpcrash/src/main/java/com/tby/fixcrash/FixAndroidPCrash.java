package com.tby.fixcrash;

import android.util.Log;

public class FixAndroidPCrash {

    static {
        try {
            System.loadLibrary("fixpcrash");
        } catch (Throwable e) {
        }
    }

    public native static void fixAndroidPCrash();
}
