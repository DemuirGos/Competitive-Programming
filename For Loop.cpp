#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string num[]= {"zero","one", "two","three","four","five","six","seven","eight","nine"};
    int a,b;cin >> a >> b;
    for(;a<=b;a++)
    {
        if(a<=9) cout << num[a]<< endl;
        else 
        {
            if(a%2) cout << "odd\n";
            else cout << "even\n";
        }
    }
    return 0;
}

