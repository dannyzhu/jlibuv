/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_oracle_libuv_handles_FileEventHandle */

#ifndef _Included_com_oracle_libuv_handles_FileEventHandle
#define _Included_com_oracle_libuv_handles_FileEventHandle
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_oracle_libuv_handles_FileEventHandle
 * Method:    _new
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_oracle_libuv_handles_FileEventHandle__1new
  (JNIEnv *, jclass);

/*
 * Class:     com_oracle_libuv_handles_FileEventHandle
 * Method:    _static_initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_oracle_libuv_handles_FileEventHandle__1static_1initialize
  (JNIEnv *, jclass);

/*
 * Class:     com_oracle_libuv_handles_FileEventHandle
 * Method:    _initialize
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_oracle_libuv_handles_FileEventHandle__1initialize
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_oracle_libuv_handles_FileEventHandle
 * Method:    _start
 * Signature: (JJLjava/lang/String;Z)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_handles_FileEventHandle__1start
  (JNIEnv *, jobject, jlong, jlong, jstring, jboolean);

/*
 * Class:     com_oracle_libuv_handles_FileEventHandle
 * Method:    _close
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_oracle_libuv_handles_FileEventHandle__1close
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif