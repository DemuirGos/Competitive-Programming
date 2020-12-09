def getmed(a):
    if(len(a)%2==0):
        return (a[len(a)//2-1]+a[len(a)//2])/2
    return a[len(a)//2]
m=int(input())
a=sorted([int(i) for i in input().split()])
print(int(getmed(a[:m//2])),int(getmed(a)),int(getmed(a[m//2:])),sep='\n')
