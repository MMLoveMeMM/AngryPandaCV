package com.panda.org.angrypandacv;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import com.panda.org.angrypandacv.core.OpenCVHelper;

public class MainActivity extends Activity {

    private Button mImageProc;
    private ImageView mImage;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mImageProc=(Button)findViewById(R.id.imageproc);
        mImageProc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Bitmap bitmap = ((BitmapDrawable) getResources().getDrawable(
                        R.mipmap.panda)).getBitmap();
                int w = bitmap.getWidth(), h = bitmap.getHeight();
                int[] pix = new int[w * h];
                bitmap.getPixels(pix, 0, w, 0, 0, w, h);
                int [] resultPixes= OpenCVHelper.gray(pix,w,h);
                Bitmap result = Bitmap.createBitmap(w,h, Bitmap.Config.RGB_565);
                result.setPixels(resultPixes, 0, w, 0, 0,w, h);
                mImage.setImageBitmap(result);
            }
        });

        mImage=(ImageView)findViewById(R.id.image);

    }
}
