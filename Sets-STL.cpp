#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<int> s;
    int t;cin >> t;
    while(t--){
        int q,x;cin >> q >> x;
        if(q==1){
            s.insert(x);
        }
        else if(q==2){
            s.erase(x);
        }
        else if(q==3){
            set<int>::iterator i=s.find(x);
            if(i==s.end()) cout << "No\n";
            else cout << "Yes\n";
        }
    } 
    return 0;
}



