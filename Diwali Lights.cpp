#include <bits/stdc++.h>
const long l=100000;
int main()
{
    int t;std::cin >>t;
    while(t--)
    {
        int n;std::cin >> n;long long m=2;long long r=1;
        while(n){
            if(n%2)
            {
                r=(r*m)%l;
            }
            m=(m*m)%l;
            n/=2;
        }
        std::cout << r-1 << std::endl;
    }
}
