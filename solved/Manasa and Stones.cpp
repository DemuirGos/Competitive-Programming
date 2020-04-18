#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n[3];for(int i=0;i<3;i++) cin >> n[i];
        set<int> s;
        for(int i=1;i<=n[0];i++){
            int c=(n[0]-i)*n[1]+(i-1)*n[2];
            s.insert(c);
        }
        for(auto i:s) cout << i << " ";cout << endl; 
    }  
}
