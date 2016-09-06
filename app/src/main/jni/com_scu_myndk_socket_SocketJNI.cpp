//
// Created by zhangqianchu on 2016/8/3.
//http://blog.csdn.net/birdsaction/article/details/17095459

#include "com_scu_myndk_socket_SocketJNI.h"
#include "common.h"
#include <android/log.h>

#define  LOG_TAG    "birds_socket"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

 const char* getSocketData(jstring addr,jint port) { //没写，这地方占时无用
   return 0;
 }

 JNIEXPORT void JNICALL Java_com_scu_myndk_socket_SocketJNI_doConnect
   (JNIEnv *env, jclass jcz, jstring addr, jint port) {
       jclass jclz = env->FindClass(env,"com/scu/myndk/socket/DataHolder");
       if (jclz) {
            jmethodID ins      = env->GetMethodID(env,jclz,"<init>","()V");
            jobject   holdObj  = env->NewObject(env,jclz,ins);
            jmethodID method1    = env->GetMethodID(env,jclz,"putData","(Ljava/lang/String;)V");
            jstring msg        = env->NewStringUTF(env,"has entering."); //只是个提示而已
            env->CallVoidMethod(env, holdObj,method1,msg);

            LOGI("connect socket.");
            const char* response =  connectRemote("172.28.151.110",9001); //,直接hardcode,这地方没有转比较简单。
            release();
            LOGI("connect socket end.");
            msg  = env->NewStringUTF(env,response);
            env->CallVoidMethod(env, holdObj,method1,msg);//数据回调给DataHolder方法中
       }
  }