from math import sqrt
f={0:1}
def F(n):
    if n in f:
        return f[n]
    else:
        f[n]=n*F(n-1)
        return f[n]
def C(n,k):
    return F(n)//(F(n-k)*F(k))
p=[2]
def G(n):
    for i in range(3,int(sqrt(n)),2):
        j=0
        is_p=1
        if i%2==0:
            continue
        while j<len(p) and p[j] <= sqrt(n):
            if(i%p[j]==0):
                is_p=0
                break; 
            j+=1
        if is_p :
            p.append(i)
inputs=[]
for t in range(int(input())):
    inputs.append(int(input()))
m=max(inputs)
G(m)
for k in inputs:
    r=0
    for i in p :
        if i <sqrt(k):
            r+=1
        else:
            break
    print(C(2*r,2))
