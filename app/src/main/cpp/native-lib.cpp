#include <jni.h>
#include <string>

extern "C" JNIEXPORT void JNICALL
Java_com_developerdaya_cppapp_MainActivity_setTextWithFormat(
        JNIEnv* env,
        jobject /* this */,
        jobject textView) {

    // Create formatted string
    std::string hello = "Hello Developer Daya";

    // Get the TextView class and the setText method
    jclass textViewClass = env->GetObjectClass(textView);
    jmethodID setTextMethod = env->GetMethodID(textViewClass, "setText", "(Ljava/lang/CharSequence;)V");

    // Convert C++ string to Java string
    jstring helloString = env->NewStringUTF(hello.c_str());

    // Call setText method on the TextView
    env->CallVoidMethod(textView, setTextMethod, helloString);

    // Now set the text size and color (can be done in Java/Kotlin side or using JNI)
    jmethodID setTextSizeMethod = env->GetMethodID(textViewClass, "setTextSize", "(F)V");
    jmethodID setBgColor = env->GetMethodID(textViewClass, "setBackgroundColor", "(I)V");
    jmethodID setTextColorMethod = env->GetMethodID(textViewClass, "setTextColor", "(I)V");

    // Set text size to 50
    env->CallVoidMethod(textView, setTextSizeMethod, 50.0f);

    // Set text color to red (#FF0000)
    env->CallVoidMethod(textView, setTextColorMethod, 0xFFFF0000);
    env->CallVoidMethod(textView, setBgColor, 0xFFFFFF00);
}
