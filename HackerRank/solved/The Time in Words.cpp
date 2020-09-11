#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,string> n;
    n[00]="o' clock";n[30]="half past ";
    n[15]="quarter past ";n[45]="quarter to ";
    map<int,string> m;
    m[1]="one";m[2]="two";m[3]="three";m[04]="four";m[05]="five";m[06]="six";m[7]="seven";m[8]="eight";m[9]="nine";m[10]="ten";m[11]="eleven";m[12]="twelve";m[13]="thirteen";m[14]="fourteen";m[15]="fifteen";m[16]="sixteen";m[17]="seventeen";m[18]="eighteen";m[19]="nineteen";m[20]="twenty";m[21]="twenty one";m[22]="twenty two";m[23]="twenty three";m[24]="twenty four";m[25]="twenty five";m[26]="twenty six";m[27]="twenty seven";m[28]="twenty eight";m[29]="twenty nine";
    int x;
    cin >> x;
    int y;
    cin >> y;
    if(y==15 || y==30 || y==00 || y==45)
    {
        if(y!=00 && y!=45)
            cout << n[y] << m[x]; 
        else if(y==45)
            cout << n[y] << m[x+1];
        else   
            cout << m[x] << " " << n[y];
    }
    else 
    {
        if(y<=30)
        {
            if(y==1)
            {
                cout << m[y] << " minute past " << m[x];
            }
            else
                cout << m[y] << " minutes past " << m[x];
        }
        else
        {
            cout << m[60-y] << " minutes to " << m[x+1];
        }
    }
    return 0;
}
