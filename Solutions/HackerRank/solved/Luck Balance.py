r=0
n,k=[int(i) for i in input().split()]
imp=[]
for _ in range(n):
    l,t=[int(i) for i in input().split()]
    if(t==0):
        r+=l
    else:
        imp.append([l,t])
imp.sort(reverse=True)
for i in range(len(imp)):
    if k > 0:
        r+=imp[i][0]
        k-=1
    else:
        r-=imp[i][0]
print(r)
