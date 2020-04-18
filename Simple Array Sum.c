#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    int* s=malloc((n+1)*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",s+i);
    }
    s[n]=-1;
    n=0;
    for(;*s!=-1;*s++){
        n+=*s;
    }
    printf("%d",n);
}
