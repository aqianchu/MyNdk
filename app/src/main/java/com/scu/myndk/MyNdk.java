package com.scu.myndk;

import android.content.Context;
import android.widget.Toast;

/**
 * Created by zhangqianchu on 2016/8/3.
 */
public class MyNdk {
    static {
        System.loadLibrary("MyLibrary");
    }

    private static Context mContext;
    public String name="天宇";
    public int age=20;
    private boolean gender=false;
    public native  String getString();

    public  MyNdk(Context context){
        this.mContext = context;
        mBytes = new byte[128];
    }
    public native String getChangeString(String str);

    public void show(String str){
        Toast.makeText(mContext,"测试:"+str,1).show();
    }

    public static void showMe(){
        Toast.makeText(mContext,"测试",1).show();
    }

    public byte[] mBytes;

    public native void changeBytes(byte[] buffer,int len);

    public native void toast(Context context);

}
