#include <bits/stdc++.h>

using namespace std;
int main()
{
    long t;cin >> t;
    while(t--)
    {
        long n;cin >> n;
        long l=(long)log2(n);
        long res=(1l<<l)-(n-(1l<<l))-1;
        cout << res << endl;
    }
}
