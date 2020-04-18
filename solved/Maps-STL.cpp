#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    map<string,int> stu2poo;
    int n;cin >> n;
    while(n--)
    {
        int i;cin >> i;
        if(i==1){
            string s;cin >> s;
            int g;cin >> g;
            if(stu2poo[s]){
                stu2poo[s]+=g;
            }
            else
                stu2poo[s]=g;
        }
        else if(i==2){
            string s;cin >> s;
            stu2poo[s]=0;
        }
        else{
            string s;cin >> s;
            if(stu2poo[s]){
                cout << stu2poo[s] << endl;
            }
            else
            {
                cout << 0 <<endl;
            }
        }
    }
    return 0;
}



