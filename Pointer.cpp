#include <stdio.h>
using namespace std;
void update(int *a,int *b) {
    int a_,b_;
    a_=*a+*b; 
    b_=(*a-*b>0)?(*a-*b):(*b-*a);
    *a=a_;*b=b_;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

