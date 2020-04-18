n=int(input())
r=0
for i in range(n*(n-1)//2,n*(n-1)//2+n):
    r+=(i*2+1)
print(r)
