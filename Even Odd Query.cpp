#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    long n;cin >> n;
    vector<int> v(n);
    while(n) cin >> v[v.size()-n--];
    long q;cin >> q;
    while(q--){
        int x,y;cin >> x >> y;
        //cout << find(x-1,y-1,v) << endl;
        printf("%s",(v[x-1]&1)?"Odd\n":x!=y?(v[x]?"Even\n":"Odd\n"):"Even\n");
    }
    
}
