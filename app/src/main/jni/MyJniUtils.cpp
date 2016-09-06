//
// Created by zhangqianchu on 2016/8/4.
//
//将JNI中将 char* 字符串转换成 jstring
jstring   CharTojstring(JNIEnv*   env,   char*   str)
{
	jsize   len   =   strlen(str);

	jclass   clsstring   =   (*env)->FindClass(env, "java/lang/String");
	jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");

	jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "<init>",   "([BLjava/lang/String;)V");
	jbyteArray   barr   =   (*env)-> NewByteArray(env,len);

	(*env)-> SetByteArrayRegion(env,barr,0,len,(jbyte*)str);
	return (jstring)(*env)-> NewObject(env,clsstring,mid,barr,strencode);
}