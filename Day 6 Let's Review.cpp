#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;cin >> t;
    while(t--)
    {
        string s;string o_s;string e_s;
        cin >> s;
        for(int i=0;i<s.size();i+=2) 
        {
            e_s.push_back(s[i]);
            if(s[i+1]!='\0')
                o_s.push_back(s[i+1]);
        }
        cout << e_s << " " << o_s << endl;
    }
}
