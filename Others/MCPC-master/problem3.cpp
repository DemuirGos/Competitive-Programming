#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long t;cin >> t;;
    while(t--)
    {
        vector<long long> v;
        long long n;cin >> n;
        while(n--)
        {
            long long m;cin >> m;v.push_back(m);
        }
        sort(v.begin(),v.end());
        long long m=0;
        for(int i=1;i<v.size();i++)
            m+=v[i];
        if(m>v[0])
            cout << m-v[0]<< "\n";
        if(m<=v[0])
            cout << v[0]-m<< "\n";
    }
}