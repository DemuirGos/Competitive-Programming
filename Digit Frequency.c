#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char* s;
    int t[10]={0,0,0,0,0,0,0,0,0,0};
    s=malloc(1024*sizeof(char));
    scanf("%s",s);
    s=realloc(s,strlen(s)+1);
    for(int i=0;i<strlen(s);i++)
    {
        
        if(s[i]-'0'<10)
        {
            t[s[i]-'0']++;
        } 
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",t[i]);
    }
    return 0;
}
