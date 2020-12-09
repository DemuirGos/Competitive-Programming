#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

bool iskaprekarNumbers(long long n) 
{ 
    long long i=n*n;
    string str=to_string(n*n);
    string str1=str.substr(0,str.size()/2);string str2=str.substr(str.size()/2);
    int resut= atoi(str1.c_str())+atoi(str2.c_str());
    if(resut==n) return true;
    return false;
}

int main()
{
    int n,l; cin >> n >> l; bool valid=0;
    for(long long i=n;i<=l;i++) if(iskaprekarNumbers(i)) { cout << i << " "; valid=1;}
    if(!valid) cout << "INVALID RANGE";
}
