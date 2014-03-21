/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_oracle_libuv_Files */

#ifndef _Included_com_oracle_libuv_Files
#define _Included_com_oracle_libuv_Files
#ifdef __cplusplus
extern "C" {
#endif
#undef com_oracle_libuv_Files_UV_FS_UNKNOWN
#define com_oracle_libuv_Files_UV_FS_UNKNOWN -1L
#undef com_oracle_libuv_Files_UV_FS_CUSTOM
#define com_oracle_libuv_Files_UV_FS_CUSTOM 0L
#undef com_oracle_libuv_Files_UV_FS_OPEN
#define com_oracle_libuv_Files_UV_FS_OPEN 1L
#undef com_oracle_libuv_Files_UV_FS_CLOSE
#define com_oracle_libuv_Files_UV_FS_CLOSE 2L
#undef com_oracle_libuv_Files_UV_FS_READ
#define com_oracle_libuv_Files_UV_FS_READ 3L
#undef com_oracle_libuv_Files_UV_FS_WRITE
#define com_oracle_libuv_Files_UV_FS_WRITE 4L
#undef com_oracle_libuv_Files_UV_FS_SENDFILE
#define com_oracle_libuv_Files_UV_FS_SENDFILE 5L
#undef com_oracle_libuv_Files_UV_FS_STAT
#define com_oracle_libuv_Files_UV_FS_STAT 6L
#undef com_oracle_libuv_Files_UV_FS_LSTAT
#define com_oracle_libuv_Files_UV_FS_LSTAT 7L
#undef com_oracle_libuv_Files_UV_FS_FSTAT
#define com_oracle_libuv_Files_UV_FS_FSTAT 8L
#undef com_oracle_libuv_Files_UV_FS_FTRUNCATE
#define com_oracle_libuv_Files_UV_FS_FTRUNCATE 9L
#undef com_oracle_libuv_Files_UV_FS_UTIME
#define com_oracle_libuv_Files_UV_FS_UTIME 10L
#undef com_oracle_libuv_Files_UV_FS_FUTIME
#define com_oracle_libuv_Files_UV_FS_FUTIME 11L
#undef com_oracle_libuv_Files_UV_FS_CHMOD
#define com_oracle_libuv_Files_UV_FS_CHMOD 12L
#undef com_oracle_libuv_Files_UV_FS_FCHMOD
#define com_oracle_libuv_Files_UV_FS_FCHMOD 13L
#undef com_oracle_libuv_Files_UV_FS_FSYNC
#define com_oracle_libuv_Files_UV_FS_FSYNC 14L
#undef com_oracle_libuv_Files_UV_FS_FDATASYNC
#define com_oracle_libuv_Files_UV_FS_FDATASYNC 15L
#undef com_oracle_libuv_Files_UV_FS_UNLINK
#define com_oracle_libuv_Files_UV_FS_UNLINK 16L
#undef com_oracle_libuv_Files_UV_FS_RMDIR
#define com_oracle_libuv_Files_UV_FS_RMDIR 17L
#undef com_oracle_libuv_Files_UV_FS_MKDIR
#define com_oracle_libuv_Files_UV_FS_MKDIR 18L
#undef com_oracle_libuv_Files_UV_FS_RENAME
#define com_oracle_libuv_Files_UV_FS_RENAME 19L
#undef com_oracle_libuv_Files_UV_FS_READDIR
#define com_oracle_libuv_Files_UV_FS_READDIR 20L
#undef com_oracle_libuv_Files_UV_FS_LINK
#define com_oracle_libuv_Files_UV_FS_LINK 21L
#undef com_oracle_libuv_Files_UV_FS_SYMLINK
#define com_oracle_libuv_Files_UV_FS_SYMLINK 22L
#undef com_oracle_libuv_Files_UV_FS_READLINK
#define com_oracle_libuv_Files_UV_FS_READLINK 23L
#undef com_oracle_libuv_Files_UV_FS_CHOWN
#define com_oracle_libuv_Files_UV_FS_CHOWN 24L
#undef com_oracle_libuv_Files_UV_FS_FCHOWN
#define com_oracle_libuv_Files_UV_FS_FCHOWN 25L
/*
 * Class:     com_oracle_libuv_Files
 * Method:    _static_initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_oracle_libuv_Files__1static_1initialize
  (JNIEnv *, jclass);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _new
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_oracle_libuv_Files__1new
  (JNIEnv *, jclass);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _initialize
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_oracle_libuv_Files__1initialize
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _close
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1close__J
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _close
 * Signature: (JILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1close__JILjava_lang_Object_2Ljava_lang_Object_2
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _open
 * Signature: (JLjava/lang/String;IILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1open
  (JNIEnv *, jobject, jlong, jstring, jint, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _read
 * Signature: (JILjava/nio/ByteBuffer;[BJJJLjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1read
  (JNIEnv *, jobject, jlong, jint, jobject, jbyteArray, jlong, jlong, jlong, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _unlink
 * Signature: (JLjava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1unlink
  (JNIEnv *, jobject, jlong, jstring, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _write
 * Signature: (JILjava/nio/ByteBuffer;[BJJJLjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1write
  (JNIEnv *, jobject, jlong, jint, jobject, jbyteArray, jlong, jlong, jlong, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _mkdir
 * Signature: (JLjava/lang/String;ILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1mkdir
  (JNIEnv *, jobject, jlong, jstring, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _rmdir
 * Signature: (JLjava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1rmdir
  (JNIEnv *, jobject, jlong, jstring, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _readdir
 * Signature: (JLjava/lang/String;ILjava/lang/Object;Ljava/lang/Object;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_oracle_libuv_Files__1readdir
  (JNIEnv *, jobject, jlong, jstring, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _stat
 * Signature: (JLjava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)Lcom/oracle/libuv/Stats;
 */
JNIEXPORT jobject JNICALL Java_com_oracle_libuv_Files__1stat
  (JNIEnv *, jobject, jlong, jstring, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _fstat
 * Signature: (JILjava/lang/Object;Ljava/lang/Object;)Lcom/oracle/libuv/Stats;
 */
JNIEXPORT jobject JNICALL Java_com_oracle_libuv_Files__1fstat
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _rename
 * Signature: (JLjava/lang/String;Ljava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1rename
  (JNIEnv *, jobject, jlong, jstring, jstring, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _fsync
 * Signature: (JILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1fsync
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _fdatasync
 * Signature: (JILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1fdatasync
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _ftruncate
 * Signature: (JIJLjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1ftruncate
  (JNIEnv *, jobject, jlong, jint, jlong, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _sendfile
 * Signature: (JIIJJLjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1sendfile
  (JNIEnv *, jobject, jlong, jint, jint, jlong, jlong, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _chmod
 * Signature: (JLjava/lang/String;ILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1chmod
  (JNIEnv *, jobject, jlong, jstring, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _utime
 * Signature: (JLjava/lang/String;DDLjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1utime
  (JNIEnv *, jobject, jlong, jstring, jdouble, jdouble, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _futime
 * Signature: (JIDDLjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1futime
  (JNIEnv *, jobject, jlong, jint, jdouble, jdouble, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _lstat
 * Signature: (JLjava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)Lcom/oracle/libuv/Stats;
 */
JNIEXPORT jobject JNICALL Java_com_oracle_libuv_Files__1lstat
  (JNIEnv *, jobject, jlong, jstring, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _link
 * Signature: (JLjava/lang/String;Ljava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1link
  (JNIEnv *, jobject, jlong, jstring, jstring, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _symlink
 * Signature: (JLjava/lang/String;Ljava/lang/String;ILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1symlink
  (JNIEnv *, jobject, jlong, jstring, jstring, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _readlink
 * Signature: (JLjava/lang/String;Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_oracle_libuv_Files__1readlink
  (JNIEnv *, jobject, jlong, jstring, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _fchmod
 * Signature: (JIILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1fchmod
  (JNIEnv *, jobject, jlong, jint, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _chown
 * Signature: (JLjava/lang/String;IILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1chown
  (JNIEnv *, jobject, jlong, jstring, jint, jint, jobject, jobject);

/*
 * Class:     com_oracle_libuv_Files
 * Method:    _fchown
 * Signature: (JIIILjava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_oracle_libuv_Files__1fchown
  (JNIEnv *, jobject, jlong, jint, jint, jint, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif