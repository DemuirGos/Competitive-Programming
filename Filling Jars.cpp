#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long n,m;cin >> n >>m;
    long long r=0;
    while(m--){
        long long x,y,l;cin >> x >> y >> l;
        r+=(y-x+1)*l;
    }
    cout << r/n;
}
