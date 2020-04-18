#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,m;cin >> n >> m;int result=0;
    map<int,int> l; vector<int> v;
    while(n--)
    {
        int a;cin >> a;l[a]++;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(l[v[i]+m]) {
            result+=l[v[i]+m];
        }
    }
    cout << result << endl;
}
