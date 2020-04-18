#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if(s.size()&1) return -1;
    int c=0;map<char,int> m;
    for(int i=0;i<s.size()/2;i++){
        m[s[i]]++;m[s[s.size()/2 + i]]--;
    }
    for(map<char,int>::iterator i=m.begin();i!=m.end();i++){
        if(i->second!=0) c+=i->second>0?i->second:-i->second;
    }
    return c/2;
}

int main()
{
    int t;cin >> t;
    while(t--){
        string s;cin >> s;
        cout << anagram(s) << endl;
    }
}
