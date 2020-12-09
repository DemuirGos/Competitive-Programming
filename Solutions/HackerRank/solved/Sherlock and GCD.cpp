#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;int g;
        int a;cin >> a;g=a;n--;
        while(n--)
        {
            cin >> a;
            g=__gcd(g,a);
        }
        if(g==1) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
}
