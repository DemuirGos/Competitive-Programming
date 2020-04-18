#include <bits/stdc++.h>

using namespace std;

// Complete the factorial function below.
int T[13];
int factorial(int n) {
    if(n<=1) return 1;
    else
    {
        return factorial(n-1)*n;
    }

}

int main()
{
    int n;cin>>n;
    cout<<factorial(n);
    return 0;
}
