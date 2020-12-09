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
    for(auto i:v)
        cout << v[i-1]<< "\n" ;
    return 0;
}
