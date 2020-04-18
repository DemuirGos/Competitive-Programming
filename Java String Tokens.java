import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s=scan.nextLine();
        for(int i=0;i<s.length();i++){
            if(Character.isLetter(s.charAt(i))){
                s=s.substring(i);
                break;
            }
        }
        String[] k=s.split("[^a-zA-Z]+");
        System.out.println(k.length);
        for(String i:k){
             System.out.println(i);
        }
    }
}
