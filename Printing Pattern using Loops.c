#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int iter=1;
  	for(int i=0;;){
        int layer=0;
        for(int j=0;j<n*2-1;j++){
            printf("%d ",n-layer); 
            if(j<i) layer++;
            if(2*n-3-layer<j) layer--;
        }
        printf("\n");
        if(iter) i++;
        else i--;
        if(i==n-1 && iter)iter--;
        if(i==-1 && !iter) break;
    }
    return 0;
}

