#include <bits/stdc++.h>

using namespace std;
long count(int n)
{
    if(n==0) return 1;
    long r=1;
    for(long i=n;i>0;i--)
        r*=i;
    return r;
}
int delta(int n)
{
    if(n==0)
        return 1;
    else 
        return n;
}
int main()
{
    string s;cin >> s;
    int n;cin >> n;
    while(n--)
    {
        map<char,int> m;int count_p=0;int count_imp=0;long div=1;
        int a,b;cin >> a >> b;
        for(int i=a-1;i<b;i++)
            m[s[i]]++;
        for(map<char,int>::iterator i=m.begin();i!=m.end();i++)
        {
            count_p+=(int)i->second/2;
            div*=count((int)i->second/2);
            if(i->second%2!=0)count_imp++;
        }    
        long result = count(count_p)*delta(count_imp)/div;
        cout << result%1000000007 << endl;
    }
}
