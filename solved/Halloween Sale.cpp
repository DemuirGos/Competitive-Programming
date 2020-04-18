#include <bits/stdc++.h>
#include <cstdio>
#define read(n) int n;scanf("%d",&n)
#define make(i,a) int i=a
#define print(a) printf("%d",a)
using namespace std;

int main()
{
    read(p);read(d);read(m);read(s);make(count,0);
    while(s-p>=0)
    {
        if(p-d<m)
        {
            count++;
            s-=m;
        }
        else
        {
            count++;s-=p;
            p-=d;
        }
    }
    print(count);
}
