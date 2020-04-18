#include <stdio.h>
int main()
{
    int n;scanf("%d",&n);
    int* v=malloc(n*sizeof(int));
    int i;
    while(i<n)
    {
        scanf("%d",v+i);i++;
    }
    for(i=n-1;i>=0;i--) printf("%d ",v[i]);

}
