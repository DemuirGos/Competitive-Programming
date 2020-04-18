#include <bits/stdc++.h>
#include <utility>
#define max(a,b,c) max(a,max(b,c))
using namespace std;
long m;
map<pair<int,int>,long> c;
long sum(vector<long> v){
    long r=0;
    for(auto k:v) r+=k;
    return r;
}
long f(vector<long>& a,long s,int i,int j) {
    if(j<=0 || i >=a.size()) return 0;
    pair<int,int> p=make_pair(i,j);
    if(c[p]) return c[p];
    c[p]=max(s%m,f(a,s-a[i],i+1,j),f(a,s-a[j-1],i,j-1));
    return c[p];
}
int main()
{
    int t;cin >> t;
    while(t--){
        long n;cin >> n >> m;
        vector<long> v(n);
        while(n){
            cin >> v[v.size()-n--];
        }
        long s=sum(v);
        cout << f(v,s,0,v.size()) << endl;
        c.clear();
    }
}
