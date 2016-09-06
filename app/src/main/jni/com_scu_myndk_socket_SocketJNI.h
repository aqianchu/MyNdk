//
// Created by zhangqianchu on 2016/8/3.
//
#include <jni.h>
#ifndef MYNDK_COM_SCU_MYNDK_SOCKET_SOCKETJNI_H
#define MYNDK_COM_SCU_MYNDK_SOCKET_SOCKETJNI_H
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_scu_myndk_MyNdk
 * Method:    getString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT void JNICALL Java_com_scu_myndk_socket_SocketJNI_doConnect
  (JNIEnv *, jobject,jstring,jint);

#ifdef __cplusplus
}
#endif
#endif //MYNDK_COM_SCU_MYNDK_SOCKET_SOCKETJNI_H
