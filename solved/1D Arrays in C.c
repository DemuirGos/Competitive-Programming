#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int sum(int* v,int n){
    if(n==0) return 0;
    return *(v+n-1)+ sum(v,n-1);
}
int main() {
    int n;scanf("%d",&n);
    int* v=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",v+i);
    printf("%d",sum(v,n));
    return 0;
}

