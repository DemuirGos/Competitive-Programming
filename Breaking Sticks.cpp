#include <bits/stdc++.h>

using namespace std;
map<long long,long long> m;
long long ls(long long t) {
    if(m[t]) return m[t];
    long long r=t*ls(1);
    for(long long i=2;i<=sqrt(t);++i)
    {
        if(t%i==0){
            long long temp=max((t/i)*ls(i),i*ls(t/i));
            r=max(r,temp);
        }
    }
    m[t]=1+r;
    return m[t];
}

int main()
{
    m[1]=1;
    int t;cin >> t;long long l=0;
    while(t--)
    {//17116054729754
        long long n;cin >> n;l+=ls(n);
    }
    cout << l;
}
