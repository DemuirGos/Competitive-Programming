#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    map<string,int> m;
    int n;cin >> n;
    while(n--) {string s; cin >> s;m[s]++;}
    cin >> n;
    while(n--) {
        string s; cin >> s;
        if(m[s]) 
        {
            cout << m[s] << "\n";
        }
        else 
        {
            cout << 0 << "\n";
        }
    }
}
