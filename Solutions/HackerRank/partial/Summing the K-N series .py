m=10**9+7
def pow_(n,k):
    t=1
    while k>0:
        if k%2==1:
            t=((t%m)*(n%m))%m
        n=((n%m)*(n%m))%m
        k>>=1
    return t%m
def sum_(n,k):
    if(n==1):
        return 1
    else:
        return (pow_(n,k)+sum_(n-1,k))%m
def sum__(n,k):
    t=0
    for i in range(1,n+1):
        t=(t+pow_(i,k)%m)%m
    return t%m
for _ in range(int(input())):
    tn,k=map(int,input().split())
    print(sum__(tn,k))
