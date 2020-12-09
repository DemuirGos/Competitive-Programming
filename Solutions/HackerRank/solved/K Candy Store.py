import math
def solve(n,k):
    c = 1
    for i in range(1,k+1):
        c=round(c)
        c =c*(n+1-i)//i
    return c
t=int(input())
for _ in range(t):
    n=int(input())
    k=int(input())
    r=solve(n+k-1,k)
    print(r%10**9)
