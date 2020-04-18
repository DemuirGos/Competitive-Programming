#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        int p;p=(int)log10(n);
        for(int i=1<<p;;i++)
        {
            bitset<32> b(i);
            long temp=0;
            for(int j=0,k=0;k<b.count();j++)
            {
                if(b[j])
                {
                    temp+=9*pow(10,j);k++;
                }
            }
            if(temp%n==0) 
            {
                cout << temp << endl;
                break;
            }
        }
    }
}
