package com.scu.myndk.entity;

/**
 * Created by zhangqianchu on 2016/8/3.
 */
public class Native {
    public static final int TEST_BUFFER_SIZE = 128;
    public byte[] mTestBuffer1;
    public byte[] mTestBuffer2;
    public native void nativeSetBuffer1(byte[] buffer,int len);
    public native void nativeSetBuffer2(byte[] buffer,int len);
    public Native(){
        mTestBuffer1 = new byte[TEST_BUFFER_SIZE];
        mTestBuffer2 = new byte[TEST_BUFFER_SIZE];
    }
    static {
        System.loadLibrary("MyLibrary");
    }
}
