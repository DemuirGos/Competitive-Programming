/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    vector<int> sums(8,0);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sums[i]+=s[i][j];sums[5-i]+=s[j][i];
        }
        sums[6]+=s[i][i];sums[7]+=s[i][2-i];
    }
    map<int,vector<int>> m;int wanted_sum=0;int mx=0;int num_of_changes=0;
    for(int i=0;i<8;i++) m[sums[i]].push_back(i);//a reviser
    for(map<int,vector<int>>::iterator i=m.begin();i!=m.end();i++)
    {
        if(i->second.size()>mx) {mx=i->second.size(); wanted_sum=i->first;} 
    }
    for(map<int,vector<int>>::iterator i=m.begin();i!=m.end();i++)
    {
        if(i->first==wanted_sum) continue;
        num_of_changes+=max(num_of_changes,wanted_sum-i->first);
    }
    return num_of_changes;
}

int main()
{
    vector<vector<int>> s;
    for(int i=0;i<3;i++)
    {
        int a,j,k;
        cin >> a >> j >> k;
        s.push_back({a,j,k});
    }
    cout << formingMagicSquare(s);
}
