#include <bits/stdc++.h>
using namespace std;
const double theta = (1+sqrt(5))/2;
const double phi = (1-sqrt(5))/2;
int main() {
    map<long,bool> m;
    int n;cin >> n;vector<long> v;long x=0;
    while(n--)
    {
        long a;cin >> a;x=max(x,a);v.push_back(a);
    }
    for(int i=0;;i++)
    {    
        long long test=(pow(theta,i)-pow(phi,i))/sqrt(5);
        m[test]=1;
        if(test>=x) break;
    }
    for(int i=0;i<v.size();i++)
    {
       if(m[v[i]]) 
            cout << "IsFibo\n";
       else 
            cout << "IsNotFibo\n";
    }
}

