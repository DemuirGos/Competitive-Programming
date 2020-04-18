#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin >> n;
    int memo=n;
    map<char,int> m;
    while(n--){
        string s;cin >> s;
        map<char,bool> temp;
        for(auto i:s){
            m[i]+=temp[i]?0:1;
            temp[i]=1;
        }
    }
    int r=0;
    for(map<char,int>::iterator i=m.begin();i!=m.end();i++){
        if(i->second==memo) r++;
    }
    cout << r << endl;
}
