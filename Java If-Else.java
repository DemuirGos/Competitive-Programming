import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        String[] s={"Not Weird","Weird"};
        if(n%2==1 || (n%2==0 && n<=20 && n>=6)) {
            System.out.println(s[1]);
        }
        else{
            System.out.println(s[0]);
        }
        scanner.close();
    }
}
