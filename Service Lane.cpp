#include <bits/stdc++.h>
#define read(a) int a;scanf("%d",&a)
#define init(a,b) int a=b
#define print(a) scanf("%d",a)
using namespace std;
int serviceLane(int a,int b,vector<int> v) {
    int m=v[a];
    for(int i=a;i<=b;i++)
        m=min(m,v[i]);
    return m;
}

int main()
{
    read(n);read(m);vector<int> v;vector<pair<int,int>> w(m);init(i,0);
    while(n--){read(t);v.push_back(t);}
    while(i<m){cin >> w[i].first;cin >> w[i].second;i++;}
    for(int i=0;i<w.size();i++) cout << serviceLane(w[i].first,w[i].second,v) << endl;
}
