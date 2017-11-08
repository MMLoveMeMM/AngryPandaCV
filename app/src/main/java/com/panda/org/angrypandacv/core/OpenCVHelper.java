package com.panda.org.angrypandacv.core;

import android.graphics.Bitmap;

/**
 * Created by rd0348 on 2017/11/7 0007.
 */

public class OpenCVHelper {
    static {
        System.loadLibrary("OpenCV");
    }
    public static native int[] Gray(int[] buf, int w, int h);

    public static native int SobelImage(Bitmap bitmap);

}
