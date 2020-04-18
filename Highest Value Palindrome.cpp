#include <bits/stdc++.h>

using namespace std;
int main()
{
    long n,k;cin >> n >> k;
    string s; cin >> s;
    long required=0;
    map<long,long> m;
    if(k>=n || n==1){
        for(;n--;)
            cout << '9';
        return 0;
    }
    if(n%2==1 && k==n-1){
        for(int i=0;i<n;i++){
            if(i==n/2) 
                cout << s[i];
            else 
                cout << '9';
        }
        return 0;
    }
    for(long i=0;i<(n+1)/2;i++){
        if(s[i]!=s[n-1-i]) {
            required++;
            m[i]=n-1-i;
        }
    }
    if(k<required) {
        cout << "-1";
        return 0;
    }
    long l=k-required;
    for(long i=0;i<l;i++){
        if(s[i]!='9' && s[n-1-i]!='9'){
            s[i]=s[n-1-i]='9';k-=2;
            if(m[i]) m[i]=-1;
        }
        else if(s[i]=='9'){
            s[n-1-i]='9';k--;
            if(m[i]) m[i]=-1;
        }
        else if(s[n-1-i]=='9'){
            s[i]='9';k--;
            if(m[i]) m[i]=-1;
        }
    }
    for(map<long,long>::iterator j=m.begin();j!=m.end();j++,k--){
        if(j->second==-1) continue;
        if(s[j->first]>s[j->second]) s[j->second]=s[j->first];
        else s[j->first]=s[j->second];
    }
    cout << s << endl;
}
