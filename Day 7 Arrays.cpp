#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;cin >> n;vector<int> v;
    while(n--){int a;cin >> a;v.push_back(a);}
    reverse(v.begin(),v.end());
    for(auto i:v) cout << i << " ";
}
