#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#define read(i) int i;cin >> i;
using namespace std;

int main()
{
    vector<int> v;
    int n,d; cin >> n >> d;
    while(n--) {read(i); v.push_back(i);}
    for(int k=0;k<v.size();k++)
    {
        cout << v[(k+d)%v.size()] << " ";
    }
}
