#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long n,p;cin >> n >> p;long long r=0;long long count=0;
    vector<int> c;
    while(n--)
    {
        long long p_c;cin >> p_c;
        c.push_back(p_c);
    }
    sort(c.begin(),c.end());
    for(long long i=0;i<c.size();i++)
    {
        count+=c[i];
        if(count<=p) r++;
    }
    cout << r << endl;
}
