#include <bits/stdc++.h>

using namespace std;

long powr(int p,int m,int b=10)
{
    long long t=1;
    while(p)
    {
        if(p&1){
            t=(t%m*b%m)%m;
        }
        b=(b*b)%m;
        p>>=1;
    }
    return t%m;
}
void f(int x,int c) {
    map<int,long> m_r; 
    for(int i=c;;++i)
    {
        long long r=0;
        for(long long j=0;j<i-1;++j)
        {
            if(m_r[i-j-2])
                r=(r%x+m_r[i-j-2])%x;
            else{ 
                m_r[i-j-2]=((4%x)*powr(i-j-2,x))%x;
                r=(r%x+m_r[i-j-2])%x;
            }
            if(r==0) {
                cout << j+i<< endl;
                return;
            }
        }
    }
}

int main()
{
   int t;cin >> t;int r=0;
   while(t--){
        int x;cin >> x;
        int count=log10(x);
        f(x,count);
   }
}
