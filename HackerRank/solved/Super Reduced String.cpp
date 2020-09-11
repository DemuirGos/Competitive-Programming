#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string SRS(string s) {
    int pos=0;char b=0;
    if(s=="") return "Empty String";
    for(int i=1;i<s.size();i++,pos++)
    {
        if(s[i]==s[pos])
        {
            s.erase(pos,2);
            b++;
        }
    }
    if(!b) return s;
    return SRS(s);
}

int main()
{
    string s;
    getline(cin, s);
    cout << SRS(s) << "\n";
}
