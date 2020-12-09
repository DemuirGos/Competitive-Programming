#include <bits/stdc++.h>

using namespace std;
int main()
{
    map<pair<int,int>,bool> m;int count=0;int c=0;
    int n,k;cin >> n >> k ;
    int r,q;cin >> r >> q ;
    while(k--)
    {
        int ri,ci;cin >> ri >> ci ;
        pair<int,int> p=make_pair(ri,ci);
        m[p]=1;
    }
    vector<bool> b(8,1);
    for(int i=1;c<8;i++)
    {
        vector<pair<int,int>> v(8);
        v[0]=make_pair(r+i,q); v[1]=make_pair(r-i,q);
        v[2]=make_pair(r,q+i);v[3]=make_pair(r,q-i);
        v[4]=make_pair(r+i,q+i);v[5]=make_pair(r-i,q-i);
        v[6]=make_pair(r-i,q+i);v[7]=make_pair(r+i,q-i);
        for(int j=0;j<8;j++)
        {
            if((m[v[j]] || v[j].first<=0 || v[j].second<=0 || v[j].first>n || v[j].second>n ) && b[j])
            {
                b[j]=0;
                c++;
            }
            if(!m[v[j]] && b[j]) {
                count++;
            }
        }
    }
    cout << count;
}
