#include <stdio.h>
#include <stdarg.h>
#define max(a,b)            (((a) > (b)) ? (a) : (b))
int max_of_n(int a,...)
{
    int m=-1;int i;
    va_list arg;
    va_start(arg,a);
    for(i=0;i<a;i++)
    {
        int temp=va_arg(arg, int);
        if(m<temp) m=temp;
    }
    va_end(arg);
    return m;
}
int max_of_four(int a,int b,int c,int d)
{
    return max(max(a,b),max(c,d));
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

