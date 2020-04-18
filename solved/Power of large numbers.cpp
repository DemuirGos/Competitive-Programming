#include <bits/stdc++.h>
using namespace std;
int pas=37;
long long mod=1000000007;
__int128 power_mod(__int128 a,__int128 b,long long m)
{
    __int128 t=1;
    while(b)
    {
        if(b%2){
            t=(t*a%m)%m;
        }
        a=(a%m*a%m)%m;
        b>>=1;
    }
    return t%m;
}
__int128 sto_int128(string n)
{
    __int128 r=0;
    for(int i=0;i<n.size();i++)
    {
        r*=10;r+=n[i]-'0';
    }
    return r;
}
__int128 parse_Mod(string s,__int128 m) {
    if(s.size()<=pas) {
        __int128 n=sto_int128(s);
        return n%m;
    }
    __int128 n=sto_int128(s.substr(0,pas));
    n=n%m*power_mod(10,s.size()-pas,m);
    return (n%m+parse_Mod(s.substr(pas),m))%m;
}
int main()
{
    int n;cin >> n;
    while(n--)
    {
        string a,b;
        cin >> a >> b;
        long long r=power_mod(parse_Mod(a,mod),parse_Mod(b,mod-1),mod);
        cout<< r << endl;
    }
}
