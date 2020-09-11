#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<bits/stdc++.h> 
#define read(a) long long a;cin >> a;
using namespace std; 
typedef long long ll;
int main()
{
    read(t);
    while(t--)
    {
        read(n);
        vector<long long> v;
        while(n--)
        {
            read(m); v.push_back(m);
        }
        //sort(v.begin(),v.end());
        ll lcm=10000000000;
        for(int i=0;i<v.size()-1;i++)
        {
            lcm=__gcd(lcm,__gcd(v[i],v[i+1])); 
        }
        if(lcm==1)
            cout << lcm << endl; 
        else
        {
            ll output=lcm;
            for (long long i=2; i<=sqrt(lcm); i++) 
            { 
                if (lcm%i == 0) 
                { 
                    output=min(output,i);
		        break;
                } 
            } 
        cout << min(output,lcm) << endl; 
        }
        

    }
}