#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int next_permutation(int n, char **s)
{
    int k=-1,i;
      for(int j=0;j<n-1;j++){
      if(strcmp(s[j],s[j+1])<0) k=j;
      if(j==n-2 && k==-1) return 0;
    }
    for(int j=k+1;j<n;j++){
        if(strcmp(s[j],s[k])>0) i=j;
    }
    char* t=s[k];s[k]=s[i];s[i]=t;
    for(int j=0;j<=(n-k-2)/2;j++){
        t=s[k+1+j];s[k+1+j]=s[n-1-j];s[n-1-j]=t;
    }
    return 1;
}
