#include <bits/stdc++.h>

using namespace std;
int makingAnagrams(string s1, string s2) {
    map<char,int> m;int c=0;
    for(auto i:s1) m[i]++;
    for(auto i:s2) m[i]--;
    for(map<char,int>::iterator i=m.begin();i!=m.end();i++){
        if(i->second!=0) c+=i->second>0?i->second:-i->second;
    }
    return c;
}

int main()
{
    string a,b;cin >> a >> b;
    cout << makingAnagrams(a,b);
}
