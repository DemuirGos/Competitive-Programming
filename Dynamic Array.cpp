#include <bits/stdc++.h>
#define read(i) int i; scanf("%d",&i)
#define write(i) printf("%d\n",i)
using namespace std;

int main()
{
    read(N);read(Q);int lstrslt=0;vector<int> empt={};
    vector<vector<int>> seqlst(N,empt);
    for(int i=0;i<Q;i++)
    {
        read(j);read(x);read(y);
        if(j==1)
            seqlst[(x^lstrslt)%N].push_back(y);
        else
            {
                lstrslt=seqlst[(x^lstrslt)%N][y%seqlst[(x^lstrslt)%N].size()];
                write(lstrslt);
            }
    }
}
