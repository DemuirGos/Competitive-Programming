#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(int base, int area){
    float t=(float)area*2/(float)base;int tt=t;
    if(t==tt) return tt;
    else return tt+1;
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}

