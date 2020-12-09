#include <iostream> 
#include <algorithm> 
#include <cmath>
using namespace std;
long long l_l,r_l;
int b[]={2,5,3,7};
void power(__int128& a,long long b,long long m)
{
    __int128 t=1;
    while(b){
        if(b&1){
            t=(t*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    a=t%m;
}
//miller rabin test
bool is_p(long long n){
    int a[] = { 2, 3, 5, 7};//int*a=b;
    for (int i = 0; i < 4; ++i)
        if (n % a[i] == 0) return n == a[i];
    if (n < a[3]) return 0;
    uint64_t t = n - 1;int s = 0;
    while (~t & 1)
        t >>= 1, ++s;
    for (int i=0;i<2; i++) {
        __int128 x=a[i];
        power(x, t, n);
        if (x == 1) continue;
        bool p = 0;
        for (int j = 0; j < s && !p; ++j) {
            if (x == n - 1) p = 1;
            power(x, 2, n);
        }
        if (!p) return 0;
    }
    return 1;
}
void f(int k,int &r,long long s=0) 
{ 
    if (k == 0) 
    {
        if(s>=l_l && s<=r_l) 
        {
            if(is_p(s)) {
                r++;
            }
        }
        return; 
    } 
    int l=(k==1)?2:0;
    for (; l < 4; l++) 
    { 
        long long inpt=s*10 + b[l];
        if(inpt>r_l) return;
        f(k-1,r,inpt); 
    } 
}
int main()
{
    cin >> l_l >>r_l;int count=0;count+=(l_l<=2) + (l_l<=5);
    for(int i=(int)log10(l_l)+1;i<=(int)log10(r_l)+1;)
        f(i++,count);
    cout << count;
}
