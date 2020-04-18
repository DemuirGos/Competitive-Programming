import java.io.*;
import java.util.*;

public class Solution {
    public static boolean is_p(String s,int i,int j){
        if((s.length()%2==1 && i==j) || (s.length()%2==0 && i==j+1 && s.charAt(i)==s.charAt(j))) return true;
        if(s.charAt(i)==s.charAt(j)){
            return is_p(s,i+1,j-1);
        }
        return false;
    }
    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        if(is_p(A,0,A.length()-1)) System.out.println("Yes");
        else System.out.println("No");
        
    }
}



