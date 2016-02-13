/*
 * Copyright (C) 2009 The Android Open Source Project
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

// OpenGL ES 2.0 code

#include <assert.h>
#include <jni.h>
#include <stdio.h>
#include <string>
using namespace std;
/*
#define  LOG_TAG    "lib4gol"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
    LOGE("Could not compile shader %d:\n%s\n",
                                       shaderType, buf);
}
*/

string encrypt_decrypt(string toEncrypt) {
    char key = 'KrggegeJUIJ__P(JIJKr52520212*&*^$*&*&#'; //Any char will work
    string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key;

    return output;
}

extern "C" {
JNIEXPORT jstring JNICALL Java_ir_sibvas_nativegol_NativeGolLib_encryptDecrypt(JNIEnv * env, jobject obj, jstring ticket);
//JNIEXPORT jstring JNICALL Java_ir_sibvas_nativegol_NativeGolLib_decrypt(JNIEnv * env, jobject obj, jstring encryptedTicket);
};

JNIEXPORT jstring JNICALL Java_ir_sibvas_nativegol_NativeGolLib_encryptDecrypt(JNIEnv * env, jobject obj,  jstring ticket)
{
    const char *simple = env->GetStringUTFChars(ticket, JNI_FALSE);
    std::string simple1(simple);
    simple1 = encrypt_decrypt(simple1);
    char *p;
    p = &simple1[0];
    return env->NewStringUTF(p);
}

//JNIEXPORT jstring JNICALL Java_ir_sibvas_nativegol_NativeGolLib_decrypt(JNIEnv * env, jobject obj, jstring ecryptedTicket)
//{
//    const char *encrypted = env->GetStringUTFChars(ecryptedTicket, NULL);
//    std::string encrypted1(encrypted);
//    encrypted1 = encrypt_decrypt(encrypted1);
//    char *p;
//    p = &encrypted1[0];
//    return env->NewStringUTF(p);
//
//}
