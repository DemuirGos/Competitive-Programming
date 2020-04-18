#include <bits/stdc++.h>
#include <string>

using namespace std;
int* calcDiff(string s){
    int* r=(int*) malloc(s.size()*sizeof(int));
    for(int i=1;i<s.size();i++){
        r[i-1]=abs((int)s[i]-(int)s[i-1]);
    }
    return r;
}
bool checkPal(int* s,int l){
    for(int i=0;i<=l/2;i++){
        if(s[i]!=s[l-1-i]) return 0;
    }
    return 1;
}
bool funnyString(string s) {
    return checkPal(calcDiff(s),s.size()-1);
}

int main()
{
    int n;cin >>n;
    while(n--){
        string s;cin >> s;
        cout << (funnyString(s)?"Funny":"Not Funny") << endl;
    }
}
