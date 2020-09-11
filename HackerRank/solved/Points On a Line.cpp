#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
bool sol(vector<bool> p) {
    for(bool i:p) if(i==1) return 1;
    return 0;
}

int main()
{
    int n;cin >> n;
    vector<long long> ve(2,0);
    vector<bool> be(2,1);
    cin >> ve[0] >> ve[1];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<2;j++)
        {
            long long a; cin >> a;
            be[j]=(a==ve[j] && be[j])?1:0;
        } 
    }
    if(sol(be)) cout << "YES" << endl;
    else cout << "NO\n" << endl;
}
