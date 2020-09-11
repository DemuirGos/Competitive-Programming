#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a;int b;
    float c;float d;
    scanf("%d",&a);scanf("%d",&b);
    scanf("%f",&c);scanf("%f",&d);
    printf("%d %d\n",a+b,a-b);printf("%.1f %.1f",c+d,c-d);
    return 0;
}

