#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
long long stoneDivision(long n,vector<long> s,map<pair<long,long>,long>& m) {
    long result=0;
    for(int i=0;i<s.size();i++){
        if(n%s[i]==0 && n!=s[i]){
            pair<long,long> b = make_pair(n,s[i]);
            if(m[b]) {
                result=result<m[b]?m[b]:result;
                continue;
            }
            m[b] = 1+(n/s[i])*stoneDivision(s[i],s,m);
            result = result<m[b]?m[b]:result;
        }
    } 
   return result;
}
int main()
{
    int q;
    cin >> q;
    while(q--){
        long n,m;
        cin >> n >> m;
        vector<long> c(m);
        map<pair<long,long>,long> mp;
        for(int i=0;i<m;i++){
            cin >> c[i];
        }
        sort(c.begin(),c.end(),greater<long>());
        cout << stoneDivision(n,c,mp) << endl;
    }
}
