#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    map<char,int> m;
    for(auto i:s) m[i]++;
    int temp=m[s[0]];bool b=true;
    for(map<char,int>::iterator i=m.begin();i!=m.end();i++)
        if((i->second==temp+1 ||i->second==1)  && b) b=false;
        else if(i->second!=temp) return "NO\n";
    return "YES";
}

int main()
{
    string s; 
    cin >> s;
    cout << isValid(s);
}
