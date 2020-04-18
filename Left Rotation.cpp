#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;scanf("%d %d",&n,&d);
    vector<int> v;
    while(n-->0)
    {
        int i;scanf("%d",&i);
        v.push_back(i);
    }
    for(int i=0;i<v.size();i++)
    {
        printf("%d ",v[(i+d)%v.size()]);
    }
}
