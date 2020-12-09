#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;


int main() {
    string s;cin >> s;
    regex r("([a-z]{5}@hogwarts[.]com)");
    if(regex_match(s,r)) cout << "Yes";
    else cout << "No";
    return 0;
}
