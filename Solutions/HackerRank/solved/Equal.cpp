#include <bits/stdc++.h>

using namespace std;
bool check(vector<int> v)
{
    int j=v[0];
    for(auto i:v)if(j!=i) return 0;
    return 1;
}
int main()
{
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;vector<int> v;int m=INT_MAX;int t=0;int r=INT_MAX;
        while(n--)
        {
            int k;cin >> k;v.push_back(k);m=min(m,k);
        }
        for(int i=m-4;i<=m;i++)
        {
            t=0;
            for(auto j:v)
            {
                t+=(int)(j-i)/5+(int)((j-i)%5)/2+(int)((j-i)%5)%2;
            }
            r=min(r,t);
        }
        cout << r << endl;
    }
}
