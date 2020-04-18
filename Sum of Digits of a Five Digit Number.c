#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int sum(int i)
{
    return i==0?0:i%10+sum((int)i/10);
}
int main() {
	
    int n;
    scanf("%d", &n);
    printf("%d",sum(n));
    return 0;
}

