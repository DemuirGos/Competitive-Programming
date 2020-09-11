#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	char *strings[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(;a<=b;a++)
        if(a<=9) printf("%s\n",strings[a]);
        else
            if(a%2) printf("odd\n");
            else printf("even\n");
    return 0;
}

