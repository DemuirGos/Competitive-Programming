#include <bits/stdc++.h>

using namespace std;
long long num1_p(long a)
{
    if(a<=0) return 0;
    long long c=0;int p=(int) log2(a);
    for(int i=0;i<p;i++)
        c+=(1ll<<(i))+(1ll<<(i-1))*i;
    c+=a-(1<<p)+1+num1_p(a-(1<<p));
    return c;
}
long long num1_n(long a)
{
    long long c=num1_p(-a-1);
    c=(-32)*a-c;
    return c;
}
int main()
{
    int t;cin >> t;
    while(t--)
    {
        long a;long b;cin >> a >> b;
        if(a>=0 && b>=0)
        {
            cout << num1_p(b)-num1_p(a-1)<<endl;
        }
        if(a<0 && b<0)
        {
            cout << num1_n(a)-num1_n(b+1)<<endl;
        }
        if(a<0 && b>=0)
        {
            cout << num1_p(b)+num1_n(a)<<endl;
        }
        if(a>=0 && b<0)
        {
            cout << num1_n(b)+num1_p(a)<<endl;
        }
    }
}
