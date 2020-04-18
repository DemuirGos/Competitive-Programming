#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;vector<long> v;bool b=false;
        long total=0;long count=0;
        while(n--)
        {
            long a;cin >> a;v.push_back(a);total+=a;
        }
        if(v.size()==1){
            cout << "YES\n";continue;
        }
        total-=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(total==count){
                b=true;break;
            }
            total-=v[i];count+=v[i-1];

        }
        if(b) cout << "YES\n";
        else
            cout << "NO\n";
    }
}
