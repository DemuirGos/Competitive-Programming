#include <bits/stdc++.h>
#define read(n) int n;cin >> n;
using namespace std;
int main()
{
    map<int,int> m;int count=0;
    read(n);read(d);vector<int> v;
    while(n--)
    {
        read(c);m[c]++;v.push_back(c);
    }
    for(int i=0;i<v.size();i++)
    {
        if(m[v[i]+d] && m[v[i]+2*d]) count++;
    }
    cout << count;
}
