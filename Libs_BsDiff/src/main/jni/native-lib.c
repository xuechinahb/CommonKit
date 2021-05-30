#include <jni.h>

#include "include/bsdiff.c"
#include "include/bspatch.c"

JNIEXPORT jint JNICALL
Java_cn_reactnative_modules_update_DiffUtil_generateDiffApk(JNIEnv *env, jclass type, jstring oldPath_,
                                               jstring newPath_, jstring patchPath_) {
    int argc = 4;
    char *argv[argc];
    argv[0] = (char *) "bspatch";
    argv[1] = (char *) (*env)->GetStringUTFChars(env, oldPath_, 0);
    argv[2] = (char *) (*env)->GetStringUTFChars(env, newPath_, 0);
    argv[3] = (char *) (*env)->GetStringUTFChars(env, patchPath_, 0);

    jint result = generateDiffApk(argc, argv);

    (*env)->ReleaseStringUTFChars(env, oldPath_, argv[1]);
    (*env)->ReleaseStringUTFChars(env, newPath_, argv[2]);
    (*env)->ReleaseStringUTFChars(env, patchPath_, argv[3]);
    return result;
}

JNIEXPORT jint JNICALL
Java_cn_reactnative_modules_update_DiffUtil_mergeDiffApk(JNIEnv *env, jclass type, jstring oldPath_,
                                            jstring newPath_, jstring patchPath_) {

    int argc = 4;
    char *argv[argc];
    argv[0] = (char *) "bspatch";
    argv[1] = (char *) (*env)->GetStringUTFChars(env, oldPath_, 0);
    argv[2] = (char *) (*env)->GetStringUTFChars(env, newPath_, 0);
    argv[3] = (char *) (*env)->GetStringUTFChars(env, patchPath_, 0);

    printf("old apk = %s \n", argv[1]);
    printf("patch = %s \n", argv[3]);
    printf("new apk = %s \n", argv[2]);

    jint result = mergeDiffApk(argc, argv);

    (*env)->ReleaseStringUTFChars(env, oldPath_, argv[1]);
    (*env)->ReleaseStringUTFChars(env, newPath_, argv[2]);
    (*env)->ReleaseStringUTFChars(env, patchPath_, argv[3]);
    return result;
}
