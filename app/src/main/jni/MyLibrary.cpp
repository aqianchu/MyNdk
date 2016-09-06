//
// Created by zhangqianchu on 2016/8/3.
//

#include "com_scu_myndk_MyNdk.h"
#include <iostream>
using namespace std;


  JNIEXPORT void JNICALL Java_com_scu_myndk_MyNdk_toast
      (JNIEnv *env,jobject thizz,jobject context){
            char buf[128]="测试本地Toast提示";
            jclass tclss = env->FindClass("android/widget/Toast");
            LOGE("buf=%s",buf);
            jmethodID jid = env->GetStaticMethodID(tclss,"makeText","(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
            LOGE("buf=%s",buf);
            jclass sclss = env->FindClass("java/lang/String");
            LOGE("buf=%s",buf);
            jmethodID mid = env->GetMethodID(sclss,"<init>","([BLjava/lang/String;)V");
            LOGE("buf=%s",buf);
            jsize len = strlen(buf);
            LOGE("buf=%s",buf);
            jbyteArray barr = env->NewByteArray(len);
            LOGE("buf=%s",buf);
            env->SetByteArrayRegion(barr,0,len,(jbyte*)buf);
            LOGE("buf=%s",buf);
            jstring strencode = env->NewStringUTF("UTF-8");
            LOGE("buf=%s",buf);
            jstring result = (jstring)env->NewObject(sclss,mid,barr,strencode);//最后一个表示使用utf-8编码的
            LOGE("buf=%s",buf);
            jobject toastt =  env->CallStaticObjectMethod(tclss,jid,context,result);
            env->DeleteLocalRef(result);//注意这里要释放jstring的引用；一定要记得析构/释放/删除申请的空间。
            env->DeleteLocalRef(strencode);
            jmethodID show_id = env->GetMethodID(tclss,"show","()V");
            env->CallVoidMethod(toastt,show_id);
            LOGE("buf=%s",buf);
      }

  JNIEXPORT jstring JNICALL Java_com_scu_myndk_MyNdk_getChangeString
      (JNIEnv *env,jobject obj,jstring prompt){
        char buf[128]="我是本地代码";
       const char *pname = env->GetStringUTFChars(prompt,NULL);

        LOGE("pname=%s",pname);

        jclass nclazz = env->GetObjectClass(obj);

        jfieldID fieldID_name = env->GetFieldID(nclazz,"name","Ljava/lang/String;");
        //jfieldID fieldID_age = env->GetFieldID(nclazz,"age","I");
        jobject name = env->GetObjectField(obj,fieldID_name);
        jmethodID func_ID = env->GetMethodID(nclazz,"show","(Ljava/lang/String;)V");
      //  env->CallVoidMethod(obj,func_ID);

        jfieldID age_ID = env->GetFieldID(nclazz,"age","I");
        env->SetIntField(obj,age_ID,200);

        jsize len = strlen(buf);
        jclass clss = env->FindClass("java/lang/String");
        jstring strencode = env->NewStringUTF("UTF-8");

        jmethodID mid = env->GetMethodID(clss,"<init>","([BLjava/lang/String;)V");
        jbyteArray barr = env->NewByteArray(len);
        env->SetByteArrayRegion(barr,0,len,(jbyte*)buf);
        jstring resultt = (jstring)env->NewObject(clss,mid,barr,strencode);
        LOGE("buf=%s",buf);
        env->CallVoidMethod(obj,func_ID,resultt);
        //jmethodID showMe_ID = env->GetStaticMethodID(nclazz,"showMe","()V");
        //env->CallStaticVoidMethod(nclazz,showMe_ID);
        LOGE("buf=%s",buf);
        char *result = strcpy(buf,pname);
        return env->NewStringUTF(result);
  }


JNIEXPORT jstring JNICALL Java_com_scu_myndk_MyNdk_getString
  (JNIEnv *env, jobject obj){
    return (*env).NewStringUTF("This is mylibrary !!!");
  }


JNIEXPORT void JNICALL Java_com_scu_myndk_MyNdk_changeBytes
  (JNIEnv *env, jobject thiz, jbyteArray buffer, jint len){
        jbyte *array = new jbyte[130];
        env->GetByteArrayRegion(buffer,0,len,array);
        LOGE("LEN:%d",len);
        if(array){
        LOGE("pBuffer is NULL");
        return;
        }
        for(int i=0;i<len;i++){
            array[i]=i;
            LOGE("pBuffer[%d]=%d",i,array[i]);
        }
  }
