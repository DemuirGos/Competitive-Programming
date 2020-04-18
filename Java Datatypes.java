import java.util.*;
import java.io.*;



class Solution{
    public static void main(String []argh)
    {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        while(n-->0){
            try{
                long q=s.nextLong();
                System.out.println(q+" can be fitted in:");
                if(q>=-128 && q<=127)System.out.println("* byte");
                if(q >= -((long)1<<15) && q <= ((long)1<<15) - 1)
                    System.out.println("* short");
                if(q >= -((long)1<<31) && q <= ((long)1<<31) - 1)
                    System.out.println("* int");
                if(q >= -((long)1<<63) && q <= ((long)1<<63) - 1)
                    System.out.println("* long");
            }
            catch(Exception e){
                System.out.println(s.next() + " can't be fitted anywhere.");
            }
        }
    }
}



