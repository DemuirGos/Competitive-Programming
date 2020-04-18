#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;cin >>n;vector<int> v(n);int i=0;
    while(i<n)
    {
        cin >> v[i];i++;
    }
    i=0;
    for(auto j=0;j<v.size();j++)
    {
        if(j+1==v[v[j]-1]) i++;
    }
    if(i==n) cout << "YES";
    else cout << "NO";
    return 0;
}
