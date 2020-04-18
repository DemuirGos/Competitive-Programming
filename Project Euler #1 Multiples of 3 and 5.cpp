#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;cin >> t;
    while(t--){
        long long n;cin >> n;
        long t,f,c;
        n--;
        c=long(n/15);
        t=long(n/3);
        f=long(n/5);
        long result = 3*(t*(t+1)/2)+5*(f*(f+1)/2)-15*(c*(c+1)/2);
        cout << result << endl;
    }
}
