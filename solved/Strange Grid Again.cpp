#include <bits/stdc++.h>

using namespace std;

int main()
{
    long c,r;cin >> r >> c;
    if(r%2)
    {
        cout << ((r-1)/2)*10+2*(c-1);
    }
    else
    {
        cout << ((r-2)/2)*10+2*(c-1)+1;
    }
}
