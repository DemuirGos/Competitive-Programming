#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,k;cin >> n>>k;
    string a,b;cin >> a >> b;
    bitset<10000> b_a(a);bitset<10000> b_b(b);
    while(k--)
    {
        string q;cin >> q;
        if(q.find("set_")!=string::npos)
        {
            if(q.find("a")!=string::npos)
            {
                int input;cin >> input;int value;cin >> value;
                b_a[input]=value;
            }
            if(q.find("b")!=string::npos)
            {
                int input;cin >> input;int value;cin >> value;
                b_b[input]=value;
            }
        }
        else
        {
            int ttl=(int)b_a.to_ulong()+(int)b_b.to_ulong();
            bitset<10000> b_c(ttl);
            int input;cin >> input;
            cout << b_c[input];
        }
    }
}
