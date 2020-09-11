#include <bits/stdc++.h>
#define read(n) int n;cin >> n
#define make(i,a) int i=a;
using namespace std;

int main()
{
    read(n);map<int,pair<int,int>> m;make(i,1);
    while(i<=n)
    {
        read(t);
        if(m[t].first) {
            if(i-m[t].first<=m[t].second) m[t].second=i-m[t].first;
            m[t].first=i;
        }
        else { 
            m[t].first=i;m[t].second=n+1;
        }
        i++;
    }
    int ans=n+1;
    for(map<int,pair<int,int>>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->second.second<ans) ans=it->second.second;
    }
    if(ans==n+1) cout << -1;
    else cout << ans;
}
