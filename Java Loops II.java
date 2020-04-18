import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int r = a;
            while(n>0){
                r+=b;
                System.out.printf("%d ",r);
                b<<=1;n--;
            }
            System.out.println();
        }
        in.close();
    }
}

