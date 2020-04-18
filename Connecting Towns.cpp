#include <bits/stdc++.h>
#define read(a) int a;cin >>a
using namespace std;

int main()
{
    read(t);
    while(t--)
    {
        read(n);long r=1;n--;
        while(n--)
        {
            long i;cin >> i;
            r=((r%1234567)*(i%1234567))%1234567;
        }
        cout << r << endl;
    }
}
