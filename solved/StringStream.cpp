#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

void parseInts(string str,vector<int>& v) {
	stringstream s(str);
    int t;
    char c;
    while(s >> t){
        v.push_back(t);
        s >> c;
    }
}

int main() {
    string str;
    cin >> str;
    vector<int> integers;
    parseInts(str,integers);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

