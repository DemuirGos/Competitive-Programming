#include <bits/stdc++.h>

using namespace std;
long f(int a,int b,int n)
{
    if(n==0) return a;
    else if(n==1) return b;
    else return f(a,b,n-1)+f(a,b,n-2);
}
int main()
{
    int t;cin >> t;
    while(t--)
    {
        int a,b,n;cin >> a >> b >> n;
        cout << f(a,b,n)%1000000007 << endl;
    }
}
