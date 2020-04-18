#include <bits/stdc++.h>

using namespace std;
long mo_p(long p,long i,long j)
{
    long r=i;
    while(j!=0)
    {
        if(j%2){
            r=(r*i%p)%p;
            j--;
        }
        i=(i*i)%p;
        j>>=1;
    }
    return r%p;
}
int main()
{
    long p;
    cin >> p;int count=0;bool f=true;
    for(long i=1;i<=p-1;i++)
    {
        map<long long,bool> m;bool b=false;
        for(long j=0;j<=p-2;j++)
        {
            long k=mo_p(p,i,j);
            if(m[k]){
                b=true;
                break;
            }
            else m[k]=true;
        }
        if(!b){
            if(f){
                cout << i << " ";
                count++;
                f=false;
            }
            else
                count++;
        }
    }
    cout <<  count;
}
