#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char* c;c=malloc(1024*sizeof(char));
    for(int i=0;i<3;i++)
        {scanf("%[^\n]%*c",c);
        printf("%s\n",c);}
    free(c);
    return 0;
}

