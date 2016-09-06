//
// Created by zhangqianchu on 2016/8/5.
//
#include "com_scu_myndk_entity_Person.h"


/*
 * Class:     com_scu_myndk_entity_Person
 * Method:    average
 * Signature: ([II)I
 */
JNIEXPORT jint JNICALL Java_com_scu_myndk_entity_Person_averages
  (JNIEnv *env, jobject thiz, jintArray jarrays, jint lens){
  jclass tclss = env->GetObjectClass(thiz);
  jfieldID fid_as = env->GetFieldID(tclss,"scores","[I");
  jintArray jint_arr = (jintArray)env->GetObjectField(thiz,fid_as);
  jint *int_arr = env->GetIntArrayElements(jint_arr,NULL);
  jsize len = env->GetArrayLength(jint_arr);
  int sum=0;
  for(int s=0;s<len;s++){
    sum+=int_arr[s];
  }
  sum /=len;
    return sum;
  }
/*
 * Class:     com_scu_myndk_entity_Person
 * Method:    average
 * Signature: ([Lcom/scu/myndk/entity/Person;)I
 */
JNIEXPORT jint JNICALL Java_com_scu_myndk_entity_Person_average
  (JNIEnv *env, jobject thiz, jobjectArray joa,jint len){
    jclass tclss = env->GetObjectClass(thiz);
    jfieldID fid = env->GetFieldID(tclss,"age","I");
    int sum=0;
    if(joa){//这里总是报joa==NULL,具体原因待查
    LOGE("len=%d",len);
    return -3;
    }
    //jobject jj = env->GetObjectArrayElement(joa,1);

    for(int i=0;i<len;i++){
       jobject jper = env->GetObjectArrayElement(joa,i);
       if(jper){return -1;}
       jint temp= env->GetIntField(jper,fid);
       if(temp){return -2;}
       sum +=temp;
    }
    sum /=len;
    return sum;
  }
