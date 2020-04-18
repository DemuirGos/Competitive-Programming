#include <bits/stdc++.h>

using namespace std;
int pow_2(long n)
{
    int p=log2(n);
    return (int)p;
}
void counterGame(long n) {
    bool p=0;
    while(1)
    {
        if(n==(1l<<pow_2(n))) {n/=2;p=!p;}
        else
        {
            n-=(1l<<pow_2(n)); p=!p;
        }
        if(n==1)
        {
            if(!p) cout << "Richard\n";
            else cout << "Louise\n";
            break;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long n;cin >> n;
        counterGame(n);
    }
    return 0;
}
