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
    static int workbook(int n, int k, int[] arr) {
        int sum=0;
        int page=1;int chap=0;int prob=arr[chap];
        for(int i=1;chap<n;i++)
        {
            if(i==page)
            {
                sum++;
            }
            if(i%k==0 && i!=prob)
            {
                page++;
            }
            if(i==prob)
            {
                chap++;
                if(chap==n)
                    break;
                prob=arr[chap];
                i=0;
                page++;
            }
        }
        return sum;
    }

    static void Main(string[] args) {
        string[] s = Console.ReadLine().Split(' ');
        int n = Convert.ToInt32(s[0]);
        int k = Convert.ToInt32(s[1]);
        int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
        int result = workbook(n, k, arr);
        Console.WriteLine(result);
    }
}
