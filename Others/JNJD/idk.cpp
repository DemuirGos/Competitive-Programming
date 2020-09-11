#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int,int> memo;
int F(int n){
  if(memo[n]) return memo[n];
  else{
    memo[n]=F(n-1)+F(n-2);
    return memo[n];
  }
}
int fx(vector<int>& pi,map<int,vector<int>> m,int a,int b){
  if(m[a].empty()){
    return -1;
  }
  else if(a==b){
    return F(pi[b]);
  }
  else{
    for(auto i:m[a]){
      return F(pi[a])+fx(pi,m,i,b);
    }
  }
}
int main(){
  int t;cin >> t;
  memo[1] = 1;
  memo[2] = 1;
  while(t--){
      int n,q;cin >> n >> q;
      vector<int> pi;
      map<int,vector<int>> m;
      for(int i=0;i<n;i++){
        int p;cin >> p;
        pi.push_back(p);
      }
      for(int i=0;i<n-1;i++){
        int a,b;cin >> a >> b;
        m[a].push_back(b);
      }
      while(q--){
        int s,f;cin >> s >> f;
        cout << fx(pi,m,s,f)<<endl;
      }
  }
}