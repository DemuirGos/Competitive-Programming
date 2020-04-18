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
    vector<int> r(n);
    for(int i=0;i<v.size();i++)
        r[v[i]-1]=i+1;
    for(auto i:r) cout << i << "\n" ;
    return 0;
}
