#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
//Complete the following function.
int main() {
    int n, k;int m_a=0;int m_o=0;int m_x=0;
    scanf("%d %d", &n, &k);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int a=i&j;int o=i|j;int x=i^j;
            if(a<k) m_a=max(m_a,a);
            if(o<k) m_o=max(m_o,o);
            if(x<k) m_x=max(m_x,x);
        }
    printf("%d\n%d\n%d\n",m_a,m_o,m_x);
    return 0;
}
