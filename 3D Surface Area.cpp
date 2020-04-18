#include <bits/stdc++.h>

using namespace std;
int abs(int n){
    return n>0?n:-n;
}
int sa(vector<vector<int>> A,int h,int w) {
    int s=0;
    for(int i=0;i<h;i++){
        s+=A[i][0];
        for(int j=0;j<w-1;j++){
            s+=abs(A[i][j]-A[i][j+1]);
        }
        s+=A[i][w-1];
    }
    for(int i=0;i<w;i++){
        s+=A[0][i];
        for(int j=0;j<h-1;j++){
            s+=abs(A[j][i]-A[j+1][i]);
        }
        s+=A[h-1][i];
    }
    return s+2*(w*h);
}

int main()
{
    int h,w;cin >> h >> w ;
    vector<vector<int>> v;
    for(int i=0;i<h;i++){
        vector<int> u;
        for(int j=0;j<w;j++){
            int o;cin >> o;u.push_back(o);
        }
        v.push_back(u);
    }
    cout << sa(v,h,w);
}
