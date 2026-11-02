package com.github.xingguangcuican;

import com.fasterxml.jackson.annotation.JsonAlias;
import com.fasterxml.jackson.databind.JsonNode;
import com.github.xingguangcuican.tools.Native;
import com.github.xingguangcuican.tools.RWFile;

public class Main {
    public static void main(String[] args) {
        Native brg = new Native();
        System.out.println(brg.echo("Java"));
        RWFile rw = new RWFile();
        JsonNode jn = rw.readFile("src/main/resources/assets/seesion.json");
    }
}