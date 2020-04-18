#include <bits/stdc++.h>

using namespace std;
int main()
{
    int feb;
    int y;scanf("%i",&y);
    if(y>1918) 
        if((y%4==0 && y%100!=0)  || (y%400==0)) feb=29;
        else feb=28;
    else if(y<1918)
        if(y%4==0) feb=29;
        else feb=28;
    else feb=15;
    printf("%d.09.%d",256-215-feb,y);
}
