#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(string n,int k) {
    if(n.size()==1)
        return n[0]-'0';
    else
    {
        long long t=0;
        for(auto i:n)
        {
            t+=i-'0';
        }
        return superDigit(to_string(t*k),1);
    }
}

int main()
{
    string n;int k; cin >> n >> k;
    cout << superDigit(n,k) ;
}
