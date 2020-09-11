#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long l,s1,s2;
    scanf("%lld %lld %lld",&l,&s1,&s2);
    long long q;scanf("%lld",&q);
    while(q--){
        long long n;scanf("%lld",&n);
        double result=sqrt(2)*(l-sqrt(n))/(s1-s2);
        result=result>0?result:-result;
        printf("%.4f\n",result);
    }
}
