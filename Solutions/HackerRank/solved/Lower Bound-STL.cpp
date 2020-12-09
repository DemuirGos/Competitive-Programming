#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;cin >> n;
    vector<int> v;
    while(n--){
        int a;cin >> a;
        v.push_back(a);
    }  
    int q;cin >> q;
    while(q--){
        int m;cin >> m;
        vector<int>::iterator l=lower_bound (v.begin(), v.end(), m);
        if(*l==m) cout << "Yes ";
        else  cout << "No ";
        cout << (l- v.begin()+1) << endl;
    }
    return 0;
}
