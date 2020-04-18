#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    if(n%2)
        cout << "Weird";
    else
    {
        if(n<=20 && n>=6)
            cout << "Weird";
        else 
            cout << "Not Weird"; 
    }
    return 0;
}
