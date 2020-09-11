#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;
int chocolateFeast(int n, int c, int m,bool p) {
    if(n/c==0)
        return 0;
    else 
    {
        if(!p)
            return n/c + chocolateFeast(n/c,m,m,1);
        return n/c + chocolateFeast(n/c+n%c,m,m,1);
    }
}

int main()
{
    int t;cin >> t;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n,c,m;cin >> n >> c >> m;
        int result = chocolateFeast(n, c, m,0);
        cout << result << "\n";
    }
}

