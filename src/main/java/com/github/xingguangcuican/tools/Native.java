package com.github.xingguangcuican.tools;

public class Native {
    static {
        System.loadLibrary("NativeBridge");
    }
    public native String echo(String hello);
}
