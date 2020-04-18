#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n;cin >> n;int c=0;
    while(n){
        if(!(n&1)){
            c++;
        }
        n>>=1;
    }
    cout << (1l<<c);
}
