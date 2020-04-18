#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
    
#define MOD 1000000007
    
long long int power(long long int n, long long int k)
{
  long long int result, pow;
  if(k==0)
    return 1;
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  result=n%MOD;
  pow=1;
  while(pow*2<=k)
  {
    pow=pow*2;
    result=(result*result);
    result=result%MOD;
  }
 
  if(k-pow!=0)
  result=result*power(n, k-pow);
  result=result%MOD;
 
  return result;
}
    
int main() {
  int t;
  cin>>t;
  while(t--)
    {
    int n;
    cin>>n;
    long long ans=0,temp;
    for(int i=0;i<n;i++)
      {
      cin>>temp;
      ans|=temp;
      }
    ans*=power(2,n-1);
    ans%=MOD;
    cout<<ans<<"\n";
   }
    return 0;
}
