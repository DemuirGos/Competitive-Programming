#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n;cin >> n;
    string s;cin >> s;
    long r=0;
    for(long i=0;i<n;i++){
        char c=' ';
        for(long j=0;!(i-j<0 || i+j>=n || s[i-j]!=s[i+j]);j++){
            if(s[i-j]==c || c==' ') {
                r++;
                c=s[i-1];
            }
            else break;
        }
        if(i==n-1 && s[i-1]==s[i]) r++;
        else if(s[i+1]==s[i] && i+1!=n-1) r++;
    }
    cout << r << endl;
}
