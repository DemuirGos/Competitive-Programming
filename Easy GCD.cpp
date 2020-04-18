#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s;long n;cin >> s >> n;
    long i;cin >>i;long g=i;s--;
    while(s--){
        cin>>i;
        g=__gcd(g,i);
    }
    bool p=false;
    {
        if(g%2==0) 
            p=true;
        else
        {
            for(int i=3;i<=sqrt(g);i+=2)
                if(g%i==0) {p=true;break;}
        }
    }
    if(!p)
    {
        if(n<g) cout << 0 << endl;
        else
            cout << (long)(n/g)*g << endl;
    }
    else
    {
        n++;
        while(n--)
        {
            if(__gcd(g,n)!=1)
            {
                cout << n << endl;
                break;
            }
        }
    }
}
