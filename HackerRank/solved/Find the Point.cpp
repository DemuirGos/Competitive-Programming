#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class point
{
    public:
    point();
    point(int a,int b)
    {
        x=a;y=b;
    }
    int x;int y;
};
int main()
{
    int n;cin >> n;
    while(n--)
    {
        int a,b,c,d;cin >> a >> b >> c >> d;
        point p(a,b);point s(c,d);point r(2*s.x-p.x,2*s.y-p.y);
        cout << r.x << " " << r.y << endl; 
    }
}
