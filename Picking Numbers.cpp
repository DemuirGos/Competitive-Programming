
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int pickingNumbers(vector<int> a,int k) {
    vector<int> p(k+1,0);
    int m=0;
    for(auto i:a) p[i]++;
    for(int i=1;i<k;i++)
    {
        m=max(m,p[i]+p[i+1]);
    }
    return m;
}

int main()
{
    int n;cin >> n;
    vector<int> a;int max=0;
    for(;n>0;n--) {
        int i;cin >> i;a.push_back(i); 
        if(i>max) max=i;
    }
    cout << pickingNumbers(a,max);
}
