def abs(n):
    if n<0:
        return -n
    return n
n=input()
l=sorted([int(i) for i in input().split()])
n=abs(l[0]-l[1])
for i in range(len(l)-1):
    n=min(n,abs(l[i]-l[i+1]))
print(n)
