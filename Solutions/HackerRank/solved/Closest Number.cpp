#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin >> t;
    while(t--)
    {
        long a,b,c;cin >> a >> b>> c;
        long temp=round(pow(a,b)/c)*c;
        cout << temp << endl;
    }
}
