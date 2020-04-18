using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {
    // Complete the solve function below.
    static void solve(long a, long b, long k, long m) {
        long c=1;
        long d=0;
        if(k==0)
        {
            a=1;
            b=0;
        }
        while(k>0)
        { 
            if(k%2==0)
            {
                long t=a;
                a=(a*a)%m-((b*b)%m+m)%m;
                b=(2*t*b)%m;
                k>>=1;
            }
            else if(k%2!=0){
                long t=c;
                c=(c*a)%m-(b*d)%m;d=(a*d)%m+(b*t)%m;
                k-=1;
            }
        }
        c=(c%m+m)%m;d=(d%m+m)%m;
        Console.WriteLine(c+" "+d);
    }

    static void Main(string[] args) {
        int n=Convert.ToInt32(Console.ReadLine());
        for(int i=0;i<n;i++)
        {
            string[] s=Console.ReadLine().Split(' ');
            long a=Convert.ToInt64(s[0]);
            long b=Convert.ToInt64(s[1]);
            long k=Convert.ToInt64(s[2]);
            long m=Convert.ToInt64(s[3]);
            solve(a,b,k,m);
        }
    }
}
