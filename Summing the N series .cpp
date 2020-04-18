#include <bits/stdc++.h>

using namespace std;

long long summingSeries(long n) {
    return ((n%1000000007)*(n%1000000007))%1000000007;
}
int main()
{
    int n;cin >> n;
    while(n--)
    {
        long a;cin >> a;
        cout << summingSeries(a) << endl;
    }
}
