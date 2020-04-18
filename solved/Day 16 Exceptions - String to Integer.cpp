#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    try{
        int n=stoi(s);
        cout << n;
    }
    catch(exception e){
        cout << "Bad String";
    }
}

