#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;cin >> n;
    vector<int> v(n+1);int i=0;
    v[0]=INT_MIN;
    while(i++<=n){cin >> v[i];}
    v.push_back(INT_MAX);
    vector<int> b(n,0);bool sorted=1;
    for(int i=0;i<=n && sorted;i++) if(v[i+1]<v[i]) sorted=0;
    if(sorted) {cout << "yes";return 0;}
    vector<int> q={};
    vector<vector<int>> seq(n,q);
    for(int i=0;i<=n;i++){
        if(v[i+1]<v[i]) q.push_back(v[i+1]);
        if(v[i+1]>v[i]) {
            seq[i]=q;
            q.clear();
        }
    }
    for(auto i:seq) {for(auto j:i) cout << j << " ";cout << endl;}





    /*int s=-1,e=-1;
    int ups=0,downs=0;bool possible=1;
    for(int i=0;i<=n && possible;i++){
        if(v[i]>v[i+1] && s==-1) {s=i;cout << i<< endl;}
        if(s && v[i]<v[i+1]) e=(i==n && e==-1)?n:i-1;
        if(s!=-1 && i==s+1 && v[i]<v[i+1]) downs++;
        if((i==e+2 || s==-1) && v[i]>v[i+1]) ups++;
    }
    cout << ups << " " << downs << " " << s  << " " << e ;*/
}
