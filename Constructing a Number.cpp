#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;int j=0;
        while(n--)
        {
            string s;
            cin >> s;
            for(auto i:s)
                if(i!=' ')
                {
                    j+=i-'0';
                } 
        }
        if((j%3)==0) cout << "Yes\n";
        else cout << "No\n";
    }
}
