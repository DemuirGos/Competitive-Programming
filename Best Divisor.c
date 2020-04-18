#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sumd(long n){
    if(n==0) return 0;
    return n%10+sumd((int)n/10);
}
int sum(long n){
    return n<10?n:sum(sumd(n));
}
int main()
{
    int result=0;
    long n;scanf("%ld",&n);
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(sumd(i)>sumd(result)) result=i;
            if(sumd(i)==sumd(result)) result=i<result?i:result;
            if(sumd(n/i)>sumd(result)) result=n/i;
            if(sumd(n/i)==sumd(result)) result=n/i<result?n/i:result;
        }
    }
    printf("%d",result);
}
