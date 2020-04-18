#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,i,m;cin >> n;i=0;
    vector<string> v;vector<int> v_s;
    while(i<n)
    {
        string s;cin >> s;
        v.push_back(s);i++;
    }
    i=0;
    while(i<n)
    {
        int a;cin >> a;
        v_s.push_back(a);i++;
    }
    cin >> n;vector<int> r;
    i=-1;m=INT_MAX;
    while(n--)
    {
        int a,b;cin >> a >> b;int t=0;
        string s;cin >> s;
        for(int j=a;j<=b;j++)
        {
            size_t f=s.find(v[j]);
            while(f!=string::npos)
            {
                t+=v_s[j];
                f=s.find(v[j],f+1);
                if(f==string::npos)
                    break;
            }
        }
        m=min(m,t);i=max(i,t);
    } 
    cout << m << " " << i;

}
