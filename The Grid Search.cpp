#include <bits/stdc++.h>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
bool GridSearch(vector<string> G, vector<string> P) {
    int j=0;int p=0;
    for(int i=0;i<=G[0].size()-P[0].size();i++)
    {
        if(G[j][i]==P[0][p]) { p++;}
        if(p==P[0].size()-1 && j<G.size()-P.size()) 
        { 
            int t=0;
            for(int l=1;l<P.size();l++)
            {
                for(int m=0;m<P[0].size();m++)
                {
                    if(P[l][m]==G[j+l][i-p+1+m]) t++;
                    else {i-=p;p=0;i++;break;}
                }
            }
            if(t==(P.size()-1)*(P[0].size())) return true;
            i-=p;i++;
            p=0;
        }
        //if(p && G[j][i+1]!=P[0][p]) p=0;
        if(i==G[0].size()-P[0].size()-1) {i=0;j++;p=0;}
        if(j==G.size()-P.size()-1) {break;}
    }
    return false;
}
int main()
{
    int t;cin >> t;
    while(t--)
    {
        int C,R;cin >> C >> R;
        vector<string> v(C,"");
        for(int i=0;i<C;i++)
        {
            cin >> v[i];
        }
        int c,r;cin >> c >> r;
        vector<string> w(c,"");
        for(int i=0;i<c;i++)
        {
            cin >> w[i];
        }
        if(GridSearch(v,w)) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}
