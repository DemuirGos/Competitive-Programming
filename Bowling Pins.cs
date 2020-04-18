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
    public static int[] theo_arr;
    static int solve(int l)
    {
        if(l==0)
            return 0;
        else if(l==1)
            return 1;
        else if(l==3)
            return 2;
        else if(theo_arr[l]!=-1)
            return theo_arr[l];
        List<int> r=new List<int>();
        //List<int> p=new List<int>();
        int m=highestPowerof2(l);
        for(int i=0;i<=m;i++)
        {
            if((l&(1<<i))>0)
            {
                l-=1<<i;int count=0;
                for(int j=0;j<=m;j++)
                    if((l&(1<<j))==0)
                    {
                        l>>=1;
                        count++;
                        j--;
                    }
                    else 
                        break;
                r.Add(solve(l));
                l<<=count;
                l+=1<<i;
            }
            else
            {
                continue;
            }
            if(i<=m-1 && (l&(1<<i))>0 && (l&(1<<(i+1)))>0)
            {
                l-=1<<i;l-=1<<(i+1);int count=0;
                for(int j=0;j<=m;j++)
                    if(l!=0 && (l&(1<<j))==0)
                    {
                        l>>=1;
                        count++;
                        j--;
                    }
                    else 
                        break;
                r.Add(solve(l));
                l<<=count;
                l+=1<<i;l+=1<<(i+1);
            }
        }
        /*p.Add(Mex(r));
        int n=p[0];
        for(int i=1;i<p.Count();i++)
            n^=p[i];*/
        int n=Mex(r);
        theo_arr[l]=n;
        return n;
    }
    static int Mex(List<int> s)
    {
        s.Sort();
        int min=0;
        for(int i=0;i<s.Count;i++){
            if(s[i]==min)
            {
                min++;
            }
            else
            {
                return min;
            }
        }
        return min;
    }
    static int highestPowerof2(int n) 
    { 
        int p = (int)Math.Log(n,2); 
        return p;  
    }    
    //--------------------------------------------------------------------------------------------------
    static void Main(string[] args) {
        int n=Convert.ToInt32(Console.ReadLine());
        for(int i=0;i<n;i++)
        {
            int m=Convert.ToInt32(Console.ReadLine());
            string s=Console.ReadLine();
            int count=(1<<m+1)-1;count>>=1;
            theo_arr=new int[count+1];
            for(int j=0;j<=count;j++)
                theo_arr[j]=-1;
            for(int c=0;c<s.Count();c++)
            {
                if((s[c]=='X'))
                {
                    count-=1<<c;
                }
                else
                {
                    continue;
                }
            }
            if(solve(count)>0)
                Console.Write("WIN\n");
            else
                Console.Write("LOSE\n");
        }
            
    }
}
