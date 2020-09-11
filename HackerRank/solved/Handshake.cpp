#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long long handshake(int n) {
    if(n==1 || n==0) return 0;
    else 
    {
        return n*(n-1)/2;
    }
}

int main()
{
    int n;cin >> n;
    while(n--)
    {
        int a;cin >> a;
        cout << handshake(a) << endl;
    }
}
