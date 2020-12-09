using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {

    static void Main(string[] args) {
        string[] line=Console.ReadLine().Split(' ');
        long n=Convert.ToInt64(line[0]);
        long q=Convert.ToInt64(line[1]);
        long[] arr=new long[n+2];
        while(q>0){
            line=Console.ReadLine().Split(' ');
            long a=Convert.ToInt64(line[0]);
            long b=Convert.ToInt64(line[1]);
            long v=Convert.ToInt64(line[2]);
            arr[a]+=v;arr[b+1]-=v;
            q--;
        }
        long m=0;long calc=0;
        for(long i=0;i<=n+1;i++)
        {
            calc+=arr[i];
            m=Math.Max(m,calc);
        }
        Console.WriteLine(m);
    }
}
