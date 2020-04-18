#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q;cin >> n >> q;
    vector<vector<int>> v;
    while(n--)
    {
        int l;cin >> l;
        vector<int> w;
        while(l--)
        {
            int t;cin >> t;
            w.push_back(t);
        }
        v.push_back(w);
    }  
    while(q--)
    {
        int i,m;cin >> i >>m;
        cout << v[i][m]<< endl;
    }
    return 0;
}

