/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
bitset<500> string2bit(string str)
{
    bitset<500> rslt(str);
    return rslt;

}
void acmTeam(vector<string> v_bt) {
    int max=0;int count=1;
    for(int i=0;i<v_bt.size()-1;i++)
    {
        for(int j=i+1;j<v_bt.size();j++)
        {
            bitset<500> temp;
            temp=string2bit(v_bt[i])|string2bit(v_bt[j]);
            if(temp.count()==max) count++;
            if(temp.count()>max) {max=temp.count();count=1;}
        }
    }
    cout << max << "\n" << count;
}

int main()
{
    int n,m;
    cin >> n >> m;//n++;
    vector<string> v_bt;
    for(int i=0;i<n;i++){
        string str;cin >> str;
        v_bt.push_back(str);
    }
    acmTeam(v_bt);
}
