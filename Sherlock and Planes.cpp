#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
bool sol(vector<bool> p) {
    for(bool i:p) if(i==1) return 1;
    return 0;
}

int main()
{
    long long t;cin >> t;
    while(t-->0){
        vector<long long> ve(3,0);
        vector<bool> be(3,1);
        cin >> ve[0] >> ve[1] >> ve[2];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
            {
                long long a; cin >> a;
                be[j]=(a==ve[j] && be[j])?1:0;
            } 
        }
        if(sol(be)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
