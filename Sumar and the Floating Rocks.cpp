#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(int x1, int y1, int x2, int y2) {
    int c=__gcd(abs(y2-y1),abs(x2-x1));
    return c-1;
}

int main()
{
    int t;cin >> t;int n=t;vector<int> v,q;
    while(t--)
    {
        int x1,y1,x2,y2;cin >> x1>>y1>>x2>>y2;
        cout << solve(x1,y1,x2,y2) << endl;
    }
}
