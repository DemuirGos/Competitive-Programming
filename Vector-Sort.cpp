#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;cin >> n;vector<int> v;
    while(n--){
        int a;cin >> a;v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(auto i:v) cout << i << " ";
    return 0;
}
