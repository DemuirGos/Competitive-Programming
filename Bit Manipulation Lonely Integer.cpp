#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;cin >> n;
    map<int,bool> m;
    while(n--) {
        int a;cin >> a;
        m[a]=m[a]?0:1;
    }
    for(map<int,bool>::iterator i=m.begin();i!=m.end();i++){
        if(i->second) cout << i->first;
    }
}
