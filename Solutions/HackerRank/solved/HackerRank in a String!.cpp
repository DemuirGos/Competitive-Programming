#include <bits/stdc++.h>

using namespace std;
string temp="hackerrank";
// Complete the hackerrankInString function below.
string hacker(string s) {
    queue<char> q;
    for(auto i:temp) q.push(i);
    for(int i=0;i<s.size();i++)
        if(q.front()==s[i])
            q.pop();
    if(q.empty())
        return "YES\n";
    else
        return "NO\n";
}

int main()
{
    int n;cin >> n;
    while(n--)
    {
        string s;cin>>s;
        cout << hacker(s);
    }
}
