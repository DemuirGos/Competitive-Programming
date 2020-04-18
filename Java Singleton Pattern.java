import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.reflect.*;


class Singleton{
    private Singleton(){};
    public String str;
    public static Singleton getSingleInstance(){
        Singleton s = new Singleton();
        return s;
    }
}