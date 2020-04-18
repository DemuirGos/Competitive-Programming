#include <bits/stdc++.h>

using namespace std;
int v[101];
// Complete the gameOfStones function below.
bool gameOfStones(int n) {
    if(n==1) return 1;
    if(n<=5 && n!=1) return 0;
    else 
    {
        if(v[n]==-1) 
        {
            v[n]=(!gameOfStones(n-2) && !gameOfStones(n-3) && !gameOfStones(n-5));
            return v[n];
        }
        return v[n];
    }

}

int main()
{
    for(int i=0;i<101;i++) v[i]=-1;
    int t;scanf("%d",&t);
    while(t--) {int n;scanf("%d",&n);
        if(gameOfStones(n))
             printf("Second\n");
        else
            printf("First\n");
        }
}
