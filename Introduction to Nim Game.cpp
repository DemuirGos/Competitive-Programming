#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;cin >>t;
    while(t--)
    {
        int n;cin >> n;vector<int> v;
        while(n--){int a;cin >> a;v.push_back(a);}
        int r=v[0];
        for(int i=1;i<v.size();i++) r^=v[i];
        if(r!=0) cout << "First\n";
        else cout << "Second\n";
    }
}
