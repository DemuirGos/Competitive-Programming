#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin >> t;
    while(t--)
    {
        unsigned int n;cin >> n;
        bitset<32> b(n);
        b.flip();
        cout << b.to_ullong() << endl;
    }
}
