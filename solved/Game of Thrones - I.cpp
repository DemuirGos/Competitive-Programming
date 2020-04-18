#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string got(string s) {
    map<char,int> m;
    for(auto i:s) m[i]++;
    bool valid=1,odd=0,l_odd=0;
    l_odd=s.size()%2==0?0:1;
    for(map<char,int>::iterator i=m.begin();i!=m.end();i++){
        if(l_odd) {
            if(i->second%2){
                if(odd){
                    valid=0;
                    break;
                }
                if(!odd) odd=true;
            }
        }
        if(!l_odd) {
            if(i->second%2)
            {
                valid=0;
                break;
            }
        }
    }
    return valid?"YES":"NO";
}

int main()
{
    string s;cin >> s;
    cout << got(s);
}
