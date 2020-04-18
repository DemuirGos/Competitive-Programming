#include <bits/stdc++.h>

using namespace std;
int main()
{
    map<char,char> m;
    m['{']='}';m['(']=')';m['[']=']';m[']']='[';m['}']='{';m[')']='(';
    int t;cin >> t;
    while(t--){
        stack<char> q;
        string s;cin >> s;
        bool v=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                q.push(s[i]);
            }
            else{
                if(!q.empty()){
                    if(s[i]==m[q.top()])
                        q.pop();
                    else{
                        v=0;break;
                    }
                }
                else{
                    v=0;break;
                }
            }
        }
        if(q.empty() && v) cout << "YES\n";
        else cout << "NO\n";
    }
}
