#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;cin >> n;vector<int> v;
    while(n--){
        int a;
        cin >> a;
        v.push_back(a);
    } 
    int m,a,b;
    cin >> m;
    cin >> a >> b;
    v.erase(v.begin()+m-1);
    v.erase(v.begin()+a-1,v.begin()+b-1);
    cout << v.size() <<  endl;
    for(auto i:v) cout << i << " ";
    return 0;
}
