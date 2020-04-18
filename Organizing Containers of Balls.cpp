 #include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> ver(n,0);vector<int> hor(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a;cin >> a;
                ver[i]+=a;hor[j]+=a;
            }
        }
        sort(hor.begin(),hor.end());sort(ver.begin(),ver.end());
        bool valid=true;
        for(int i=0;i<n && valid;i++){
            if(hor[i]!=ver[i]) valid=!valid;
        }
        if(valid) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}
