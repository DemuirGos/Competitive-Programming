#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;//another work in progress
int T[34];
int rev(long n) 
{ 
    int p = (int)log2(n); 
    return p;  
} 
vector<double> count_1(int n)
{
    double r=0;float c=0;
    for(int i=0;i<n;i++)
    {
        long b_1=1L<<i;long c_1=(1L<<(i-1))*i;int l_n=i+1; 
        r+=(double)(b_1+c_1)/l_n;
        c+=(b_1+c_1);
    }
    T[n]=c;
    return {r,c};
}
vector<double> count_1(int m,long n,long k)
{
    double r=0;
    for(int i=0;i<n;i++)
    {
        long b_1=1L<<i;long c_1=(1L<<(i-1))*i;
        r+=(b_1+c_1);
    }
    r+=(k+1);
    return {(double)r/(m+1),r};
}
void solve(long a,long b)
{
    int f_b = rev(b);int f_a=rev(a);long  count=b-a+1;
    long b_2=b-(1L<<f_b);long a_2=a-1-(1L<<f_a);double r=0;double c=0;
    //cout << b << " - 2^"<< f_b << " = " << b_2 << endl;
    {
        r+=count_1(f_b)[0];r-=count_1(f_a)[0];
        c+=count_1(f_b)[1];c-=count_1(f_a)[1];
        while(b_2>=0)
        {
            int f_t=rev(b_2);
            r+=count_1(f_b,f_t,b_2)[0];
            c+=count_1(f_b,f_t,b_2)[1];
            b_2=b_2-(1L<<f_t);
        }
        while(a_2>=0)
        {
            int f_t=rev(a_2);
            r-=count_1(f_a,f_t,a_2)[0];
            c-=count_1(f_a,f_t,a_2)[1];
            a_2=a_2-(1L<<f_t);
        }
    }
    cout << r/count << " " << c/count << endl;
}
int main() {
    int t;cin >> t;
    cout.setf(ios::fixed, ios::floatfield); cout.precision(5);
    while(t--)
    {
        long a,b; cin >> a  >> b;
        solve(a,b);
    }
    return 0;
}
