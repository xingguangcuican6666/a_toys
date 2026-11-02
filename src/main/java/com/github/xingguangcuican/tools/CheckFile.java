package com.github.xingguangcuican.tools;

import java.io.File;

public class CheckFile {
    public static Boolean ifFileext(String path){
        File aFile = new File(path);
        if(aFile.exists()) return true;
        return false;
    }
}
