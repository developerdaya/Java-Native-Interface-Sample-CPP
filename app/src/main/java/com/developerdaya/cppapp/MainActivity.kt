package com.developerdaya.cppapp

import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    init {
        System.loadLibrary("cppapp")
    }

    // Declare the native method
    external fun setTextWithFormat(textView: TextView)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val textView: TextView = findViewById(R.id.sample_text)
        setTextWithFormat(textView)
    }
}
