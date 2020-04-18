#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string n;cin>>n;
    int e;cin >> e;
    for(int i=0;i<n.size();i++){
        cout << (char)((n[i]-'0'+e)%10+'0');
    }
    return 0;
}
