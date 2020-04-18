#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m; cin >> n >> m;
    bool v=1;
    map<string,int> c;
    while(n--){
        string s; cin >> s;
        c[s]++;
    }
    while(m--){
        string s; cin >> s;
        c[s]--;
    }
    for(map<string,int>::iterator i=c.begin();i!=c.end() && v;i++)
    {
        if(i->second<0){
            v=0;
        }
    }
    cout << (v?"Yes":"No");
}
