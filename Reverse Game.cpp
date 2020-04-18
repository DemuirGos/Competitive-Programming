#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;cin>>n>>k;int r;
        r=(k<n-1-k)?2*k+1:2*(n-k-1);
        cout << r << endl;
    }
}
