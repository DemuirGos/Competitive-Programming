#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int restaurant(int l, int b) {
    int g=__gcd(l,b);
    return (l*b)/(g*g);
}

int main()
{
    int t;cin >> t;
    while(t--){
        int l,w;cin >> l >> w;
        cout << restaurant(l,w) << endl;;
    }
}
