package com.github.xingguangcuican.tools;

import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;

public class RWFile {
    static {
        System.loadLibrary("NativeBridge");
    }

    public native JsonNode readFile(String path);
    
    ObjectMapper a = new ObjectMapper();
}
