#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;cin >> n;
    map<string,int> m;
    while(n--)  
    {
        string s;int a;
        cin >> s;cin >> a;
        m[s]=a; 
    }
    string s;
    getline(cin,s);
    while (getline(cin, s))
    {
        if(m[s])    cout << s <<"="<<m[s]<<endl;
        else cout << "Not found"<<endl;
    }
    return 0;
}

