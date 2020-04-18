#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    map<int,int> m;bool b=true;
    int n;cin >> n;
    while(n--)
    {
        int a;cin >> a;
        m[a]++;
    }
    for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
        if(i->second>1){
            b=false;
            break;
        }
    if(b)
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}
