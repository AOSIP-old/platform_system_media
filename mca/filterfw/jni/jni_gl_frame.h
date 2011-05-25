/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef JNI_GL_FRAME_H
#define JNI_GL_FRAME_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_allocate(JNIEnv* env, jobject thiz, jint width, jint height);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_allocateWithTexture(JNIEnv* env,
                                                       jobject thiz,
                                                       jint tex_id,
                                                       jint width,
                                                       jint height,
                                                       jboolean owns,
                                                       jboolean create);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_allocateWithFbo(JNIEnv* env,
                                                   jobject thiz,
                                                   jint fbo_id,
                                                   jint width,
                                                   jint height,
                                                   jboolean owns,
                                                   jboolean create);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_allocateExternal(JNIEnv* env, jobject thiz);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_deallocate(JNIEnv* env, jobject thiz);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_setNativeInts(JNIEnv* env, jobject thiz, jintArray ints);

JNIEXPORT jintArray JNICALL
Java_android_filterfw_core_GLFrame_getNativeInts(JNIEnv* env, jobject thiz);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_setNativeFloats(JNIEnv* env, jobject thiz, jfloatArray ints);

JNIEXPORT jfloatArray JNICALL
Java_android_filterfw_core_GLFrame_getNativeFloats(JNIEnv* env, jobject thiz);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_setNativeData(JNIEnv* env,
                                                 jobject thiz,
                                                 jbyteArray data,
                                                 jint offset,
                                                 jint length);

JNIEXPORT jbyteArray JNICALL
Java_android_filterfw_core_GLFrame_getNativeData(JNIEnv* env, jobject thiz);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_setNativeBitmap(JNIEnv* env,
                                                   jobject thiz,
                                                   jobject bitmap,
                                                   jint size);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_getNativeBitmap(JNIEnv* env, jobject thiz, jobject bitmap);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_setNativeViewport(JNIEnv* env,
                                                     jobject thiz,
                                                     jint x,
                                                     jint y,
                                                     jint width,
                                                     jint height);

JNIEXPORT jint JNICALL
Java_android_filterfw_core_GLFrame_getNativeTextureId(JNIEnv* env, jobject thiz);

JNIEXPORT jint JNICALL
Java_android_filterfw_core_GLFrame_getNativeFboId(JNIEnv* env, jobject thiz);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_generateNativeMipMap(JNIEnv* env, jobject thiz);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_setNativeTextureParam(JNIEnv* env,
                                                         jobject thiz,
                                                         jint param,
                                                         jint value);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_nativeCopyFromNative(JNIEnv* env,
                                                        jobject thiz,
                                                        jobject frame);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_nativeCopyFromGL(JNIEnv* env,
                                                    jobject thiz,
                                                    jobject frame);

JNIEXPORT jboolean JNICALL
Java_android_filterfw_core_GLFrame_nativeFocus(JNIEnv* env, jobject thiz);

#ifdef __cplusplus
}
#endif

#endif /* JNI_GL_FRAME_H */
