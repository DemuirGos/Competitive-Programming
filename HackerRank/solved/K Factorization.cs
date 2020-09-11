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
        string[] s=Console.ReadLine().Split(' ');
        int n=Convert.ToInt32(s[0]);
        int m=Convert.ToInt32(s[1]);
        s=Console.ReadLine().Split(' ');
        ArrayList list = new ArrayList();
        ArrayList rslt = new ArrayList();
        foreach(var a in s)
        {
            int t=Convert.ToInt32(a);
            if(n%t==0)
                list.Add(t);
        }
        list.Sort();
        for(int i=list.Count-1;i>=0;i--)
        {
            int temp=n/Convert.ToInt32(list[i]);
            rslt.Add(list[i]);
            for(int j=i;j>=0;j--)
            {
                if(temp%Convert.ToInt32(list[j])!=0)
                    continue;
                else
                {
                    rslt.Add(list[j]);
                    temp/=Convert.ToInt32(list[j]);
                    if(temp%Convert.ToInt32(list[j])==0)
                        j++;
                }
            }
            if(temp==1)
            {
                
                break;
            }
            else
                rslt.Clear();
        }
        if(rslt.Count==0)
            Console.Write(-1);
        else
        {
            int tempo=1;
            for(int i=rslt.Count-1;i>=0;i--)
            {
                Console.Write(tempo + " ");
                tempo*=Convert.ToInt32(rslt[i]);
            }
            Console.Write(tempo + " ");
        }
    }
}
