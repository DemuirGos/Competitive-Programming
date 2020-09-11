#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int M[15][15];
bool chessboardGame(int x, int y) {
    if(x<1 || x>15 || y<1 || y>15)
    {
            return 0;
    }
    if(x<=2 && y<=2) 
    {
        M[x-1][y-1]=1;
        return M[x-1][y-1];
    }
    else 
    {
        if(M[x-1][y-1]!=-1) return M[x-1][y-1];
        M[x-1][y-1]=!chessboardGame(x-2,y+1) & !chessboardGame(x-2,y-1) & !chessboardGame(x+1,y-2) & !chessboardGame(x-1,y-2);
        return M[x-1][y-1];
    }
}

int main()
{
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            M[i][j]=-1;
    int t;scanf("%d",&t);
    while(t--)
    {
        int x,y;scanf("%d %d",&x,&y);
        if(chessboardGame(x, y))
        {
            printf("Second\n");
        }
        else 
        {
            printf("First\n");
        }
    }
}
