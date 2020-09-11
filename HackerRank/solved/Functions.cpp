#include <iostream>
#include <cstdio>
#include<stdarg.h>
using namespace std;

int max_of_n(int n...)
{
    int M=0;
    va_list l;
    va_start(l,n);
    for(int i=0;i<n;i++)
    {
        int a =va_arg(l,int);
        if(a>=M) M=a;
    }
    return M;
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_n(4,a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

