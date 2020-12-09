#include <bits/stdc++.h>
#include <regex>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    smatch m;
    regex upper("[A-Z]");
    regex lower("[a-z]");
    regex number("[0-9]");
    regex weird("[!@#$%^&*()--+]");
    int count=0;
    if(regex_search(s,m,upper)) count++;
    if(regex_search(s,m,lower)) count++;
    if(regex_search(s,m,number)) count++;
    if(regex_search(s,m,weird)) count++;
    if(s.size()>=6)
    {
        if(count==4)
            cout << 0;
        else
        {
            cout << 4-count;
        }
    }
    else
    {
        cout << max(4-count,6-n);
    }
}
