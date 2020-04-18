#include <bits/stdc++.h>

using namespace std;


int bin(unsigned n) 
{ 
    int c=0;int t=0;
    while(n>0)
    {
        if(n&1)
            c++;
        else
        {
            t=max(c,t);
            c=0;
        }
        n=n>>1;
        t=max(c,t);
    }
    return t;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << bin(n);
    return 0;
}
