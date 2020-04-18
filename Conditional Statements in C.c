#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



int main()
{
    int n;scanf("%d",&n);
    char *strings[] = {"zero","one","two","three","four","five",
                                "six","seven","eight","nine"};
    if(n<=9)
        printf("%s",strings[n]);
    else
        printf("Greater than 9");
    return 0;
}
