#include <bits/stdc++.h>
using namespace std;
char* s;
int n;
map<pair<int,int>,int> m;
int big_Pal(int a,int b)
{

    pair<int,int> p=make_pair(a%n,b%n);
    if(m[p]) return m[p]; 
    else
    {
        if(a%n==b%n)
        {
            m[p]=1;
            return m[p];
        }
        for(int i=0;i<=(b-a)/2;i++)
        {
            if(s[(a+i)%n]!=s[(b-i)%n])
            {
                m[p]=max(big_Pal(a+1,b),big_Pal(a,b-1));
                return m[p];
            }     
        }
        m[p]=b-a+1;
        return m[p];
    }
}
int main()
{
    scanf("%d",&n);s=(char*)malloc((n+1)*sizeof(char));
    scanf("%s",s);
    int i=0;
    while(i<n)
    {
        int count=big_Pal(i,n-1+i);
        cout << count << "\n";i++;
    }
}
