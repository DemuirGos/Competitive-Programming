#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;cin >> n;
    int* a=new int[n];
    for(int i=0;i<n;i++)
        cin >> a[n-1-i];
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
