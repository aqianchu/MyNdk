//
// Created by zhangqianchu on 2016/8/3.
//

#include "com_scu_myndk_entity_Native.h"

/*
 * Class:     com_scu_myndk_entity_Native
 * Method:    nativeSetBuffer1
 * Signature: ([BI)V
 */
JNIEXPORT void JNICALL Java_com_scu_myndk_entity_Native_nativeSetBuffer1
  (JNIEnv *env, jobject thiz, jbyteArray buffer, jint len){
        unsigned char array[com_scu_myndk_entity_Native_TEST_BUFFER_SIZE];
        //直接将java端的数组拷贝到本地的数据中，建议使用这种方法，更安全。
        env->GetByteArrayRegion(env,buffer,0,len,array);
        //可以通过array来访问这段数组的值了，逐一，修改的指示本地的值，Java端不会同时改变数组的值
        int i=0;
        for(i = 0;i<com_scu_myndk_entity_Native_TEST_BUFFER_SIZE;i++){
            array[i]=i;
        }
  }

/*
 * Class:     com_scu_myndk_entity_Native
 * Method:    nativeSetBuffer2
 * Signature: ([BI)V
 */
JNIEXPORT void JNICALL Java_com_scu_myndk_entity_Native_nativeSetBuffer2
  (JNIEnv *env, jobject thiz, jbyteArray buffer, jint len){
        //将本地指针直接指向含有Java端数组的内存地址，依赖JVM的具体实现
        //可能是锁住Java端的那段数组不能被回收（增加引用计数），也可能是JVM在堆上对该数组的一份拷贝
        //速度和效率要比GetByteArrayRegion方法高很多
        unsigned char *pBuffer=env->GetByArrayElements(env,buffer,NULL);
        if(pBuffer){
            return;
        }
        //可以通过pBuffer指针来访问这段数组的值了，注意：修改的是堆上面的值，Java端会同步改变，
        //不同jvm会有不同实现，不建议通过本地方法改变Java端的数组值。
        int i=0;
        for(i=0;i<com_scu_myndk_entity_Native_TEST_BUFFER_SIZE;i++){
            pBuffer[i] = i;
        }
        env->ReleaseByteArrayElements(env,buffer,pBuffer,0);
  }
