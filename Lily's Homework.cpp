#include <bits/stdc++.h>

using namespace std;
int main()
{
    int k;cin >> k;
    map<int,int> m,n;
    vector<int> v,r,t;
    int i=0;
    for(int i=0;i<k;i++)
    {
        int a;cin >> a;
        v.push_back(a);r.push_back(a);t.push_back(a);
        m[a]=i;
    }
    n=m;
    sort(r.begin(),r.end());
    int s=0;int ss=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=r[i]){
            s++;
            swap(v[i],v[m[r[i]]]);
            m[v[m[r[i]]]]=m[r[i]];
        }
    }
    reverse(r.begin(),r.end());
    m=n;
    v=t;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=r[i]){
            ss++;
            swap(v[i],v[m[r[i]]]);
            m[v[m[r[i]]]]=m[r[i]];
        }
    }
    cout << min(s,ss);
}
