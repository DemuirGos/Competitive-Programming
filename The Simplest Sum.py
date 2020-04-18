from math import *
mo=10**9+7
def pew(a,b,m):
    t=1
    while b>0:
        if b%2!=0:
            t=((t%m)*(a%m))%m
        a=((a%m)*(a%m))%m
        b>>=1
    return t%m
def f(k,n):
    m=floor(log((k-1)*n+1)/log(k))
    return int((1/(1-k))*(m-k*(1-k**m)/(1-k)))
for _ in range(int(input())):
    k,a,b=map(int,input().split())
    r=0
    for i in range(a,b+1):
       r+=f(k,i)%mo
    print(r%mo) 
