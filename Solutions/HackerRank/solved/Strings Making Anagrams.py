a=input()
b=input()
d={}
r=0
def abs(n):
    if(n<0):
        return -n
    return n
for i in range(len(a)):
    if a[i] not in d:
        d[a[i]]=1
    else:
        d[a[i]]+=1
for i in range(len(b)):
    if b[i] not in d:
        d[b[i]]=-1
    else:
        d[b[i]]-=1
for i in d:
    if d[i]!=0:
        r+=abs(d[i])
print(r)
