#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
void insert(int s,int f,map<int,set<int>>& graph){
    graph[s].insert(f);
    graph[f].insert(s);
}
void traverse(int n,map<int,set<int>>& g, map<int,bool>& p){
    if(!p[n]){
        p[n]=true;
        for(auto i:g[n]){
            traverse(i,g,p);
        }
    }
}
void problemA(){
    int n,m,q;cin >> n >> m >> q;
    map<int,set<int>> graph;
    for(int i=0;i<m;i++){
        int s,f;cin >> s >> f;
        insert(s,f,graph);
    }
    while(q--){
        int r=0;
        map<int,bool> processed;
        int s,f; cin >> s >> f;
        insert(s,f,graph);
        traverse(1,graph,processed);
        for(auto i=processed.begin();i!=processed.end();i++){
            if(i->second) r++;
        }
        cout << n-r << endl;
    }
}
void problemC(){
    int n;cin >> n;
    int prev;cin >> prev;n--;
    bool b=1;
    while(n--){
        int c;cin >> c;
        if(c-prev<0){
            b=0;
            break;
        }
        prev=c;
    }
    cout << (b?"Yes":"No") << endl;
}
long survive(int n,int k){
    cout << n << " " << k << endl;
    if(n==0) return k;
    return survive(n--,(k+1)%n);
}
void problemF(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        cout << survive(n,n) << endl;
    }
}
int main(){
    problemF();
}