#include <jni.h>

#include "com_github_xingguangcuican_tools_Native.h"
#include "com_github_xingguangcuican_tools_RWFile.h"

#include <string>
#include <filesystem>
#include <fstream>

JNIEXPORT jstring JNICALL
Java_com_github_xingguangcuican_tools_Native_echo(
        JNIEnv* env,
        jobject,
        jstring hello) {
    if (hello == nullptr) {
        return env->NewStringUTF("");
    }

    const char* value = env->GetStringUTFChars(hello, nullptr);
    if (value == nullptr) {
        return nullptr;
    }

    std::string result = "Native: ";
    result += value;
    env->ReleaseStringUTFChars(hello, value);

    return env->NewStringUTF(result.c_str());
}

JNIEXPORT jobject JNICALL Java_com_github_xingguangcuican_tools_RWFile_readFile(JNIEnv * env, jobject, jstring path){
    jclass a = env->FindClass("com/fasterxml/jackson/databind/ObjectMapper");


    jclass exception = env->FindClass("java/lang/NullPointerException");
    jmethodID constructor = env->GetMethodID(
        exception,
        "<init>",
        "(Ljava/lang/String;)V");
    jstring message = env->NewStringUTF("fasterxml not found!");
    jobject exceptiona = env->NewObject(
        exception,
        constructor,
        message
    );

    if(a == nullptr){
        env->Throw(static_cast<jthrowable>(exceptiona));
        env->DeleteLocalRef(exception);
        env->DeleteLocalRef(message);
        return nullptr;
    };

    jmethodID ainit = env->GetMethodID(a,"<init>","()V");
    jobject ainit_obj = env->NewObject(a,ainit);
    jmethodID readtree = env->GetMethodID(a,"readTree","(Ljava/lang/String;)Lcom/fasterxml/jackson/databind/JsonNode;");
    const char* input_arg = env->GetStringUTFChars(path,nullptr);
    if (input_arg == nullptr) {
        return nullptr;
    }

    std::ifstream inf(input_arg,std::ios_base::in);
    env->ReleaseStringUTFChars(path,input_arg);

    if(!inf){
        inf.close();
        env->ThrowNew(env->FindClass("java/io/IOException"),"File not found!");
        return nullptr;
    }

    std::string getfile(
        (std::istreambuf_iterator<char>(inf)),
        std::istreambuf_iterator<char>());
    inf.close();

    jstring newstring = env->NewStringUTF(getfile.c_str());
    jobject result = env->CallObjectMethod(
        ainit_obj,
        readtree,
        newstring
    );

    env->DeleteLocalRef(ainit_obj);
    env->DeleteLocalRef(a);
    env->DeleteLocalRef(newstring);

    if(env->ExceptionCheck()){
        return nullptr;
    }

    return result;

}