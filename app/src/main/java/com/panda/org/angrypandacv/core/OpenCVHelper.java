package com.panda.org.angrypandacv.core;

/**
 * Created by rd0348 on 2017/11/7 0007.
 */

public class OpenCVHelper {
    static {
        System.loadLibrary("OpenCV");
    }
    public static native int[] gray(int[] buf, int w, int h);
}
