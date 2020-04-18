#include <bits/stdc++.h>

using namespace std;
int max(int a,int b)
{
    return a<b?b:a;
}
int main()
{
    int n,m;cin >> n >> m;
    if(n==m)
        cout << 0;
    else
    {
        vector<int> c;
        while(m--)
        {
            int a;cin >> a;c.push_back(a);
        }
        sort(c.begin(),c.end());
        int count=0;
        for(int it=0;it<c.size();it++)
        {
            if(it==0 && c.size()!=1)
            {
                count=max(count,c[it]);
            }
            else if((it==c.size()-1 && n-1>c[it]) && c.size()!=1) 
            {
                int k=n-1-c[it];
                count=max(count,k);    
            }
            else if(c.size()==1)
            {
                count=max(n-1-c[0],c[0]);
            }
            else
            {
                int k=(c[it]-c[it-1])/2;
                count=max(count,k);
            }
        }
        cout << count;
    }

}
