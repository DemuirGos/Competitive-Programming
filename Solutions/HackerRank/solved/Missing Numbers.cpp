#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;map<int,int> l1;
    cin >> n;
    while(n--){
        int a;cin >> a;l1[a]++;
    }
    cin >> n;
    while(n--){
        int b;cin >> b;l1[b]--;
    }
    for(map<int,int>::iterator i=l1.begin();i!=l1.end();i++)
    {
        if(i->second) cout << i->first << " ";
    }
}
