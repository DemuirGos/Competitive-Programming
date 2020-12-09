#include <bits/stdc++.h>
#include <cmath>
using namespace std;
vector<long long> gener(long long n) {
    vector<long long> v={2};
    long long count=1;
    for(int i=3;i<n;i+=2)
    {
        bool b=true;
        long double l =sqrt(i);
        if(l-(int)l==0) continue;
        for(int j=0;v[j]<l;j++)
        {
            if(i%v[j]==0) {
                b=false;
                break;
            }
        }
        if(b)
        {
            v.push_back(i);
            count*=i;
        }
        if(count>n) break;
    }
    return v;
}

int main()
{
    int t;cin >> t;long long l=-1;
    vector<long long> queries;
    while(t--){
        long long m;cin >> m;queries.push_back(m);l=max(l,m);
    }
    vector<long long> p=gener(l);
    for(auto i:queries)
    {
        if(i<2) {cout << 0 << endl;continue;}
        long double r=1;int j=0;
        for(j=1;r<=i;j++)
        {   
            r*=p[j-1];
            if(r==i) {cout << j << endl;break;}
            if(r>i){cout << j-1<<endl;break;}
        }
    }
}
