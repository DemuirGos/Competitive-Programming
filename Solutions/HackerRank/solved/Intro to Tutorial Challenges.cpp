#include <bits/stdc++.h>

using namespace std;
int main()
{
    int v;cin >> v;
    int n;cin >> n;
    for(int i=0;i<n;i++)
    {
        int a;cin >> a;
        if(a==v){
            cout << i;break;
        }
    }

}
