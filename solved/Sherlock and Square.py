m=10**9+7
def pew(a,b):
    t=1
    while b>0:
        if b%2==1:
            t=(t%m)*(a%m)
        a=(a%m)*(a%m)
        b>>=1
    return t%m
for _ in range(int(input())):
    n=int(input())
    print((pew(2,n+1)+2)%m)
