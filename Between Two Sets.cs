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

class Result
{
    public static int getTotalX(List<int> a, List<int> b)
    {
        int n=GCD(b);
        int m=LCM(a);
        if(m>n || m<0)
            return 0;
        int count=0;
        for(int j=m;j<=n;j++)
        {
            if(j%m==0 && n%j==0)
                count++;
        }
        return count;
    }
    static int GCD(int a, int b)
    {
         return b == 0 ? a : GCD(b, a % b);
    }
    static int GCD(List<int> l)
    {
        int n=l[0];
        foreach(var i in l)
            n=GCD(i,n);
        return n;
    }
    static int LCM(int a, int b)
    {
         return b*a/GCD(a,b);
    }
    static int LCM(List<int> l)
    {
         int n=l[0];
         for(int i=1;i<l.Count();i++)
            n=  LCM(n,l[i]);
        return n;
    }
    public static void Main(string[] args)
    {
        string[] s=Console.ReadLine().Split(' ');
        int n=Convert.ToInt32(s[0]);
        int m=Convert.ToInt32(s[1]);
        List<int> l=new List<int>(n);
        List<int> r=new List<int>(m);
        s=Console.ReadLine().Split(' ');
        foreach(var _s in s)
            l.Add(Convert.ToInt32(_s));
        s=Console.ReadLine().Split(' ');
        foreach(var _s in s)
            r.Add(Convert.ToInt32(_s));
        Console.Write(getTotalX(l,r));
    }
}
