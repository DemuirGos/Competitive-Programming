#include <bits/stdc++.h>

using namespace std;
int p[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main()
{
    int n,m;cin >> n;m=n;
    vector<string> v;
    while(m--){
        string s;cin >> s;
        v.push_back(s);
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++)
        {
            bool c=1;
            for(int k=0;k<4 && c;k++){
                if(v[i][j]<=v[i+p[k][0]][j+p[k][1]]) c=0;;
            }
            v[i][j]=c?'X':v[i][j];
        }
    }
    for(auto i:v) cout << i << endl;
}
