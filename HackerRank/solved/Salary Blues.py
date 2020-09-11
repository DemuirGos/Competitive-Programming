import math
def Great_Gcd(m):
    g=[m[0],True]
    temp=m[0]
    for i in m:
        if g[1] and temp!=i:
            g[1]=False
        g[0]=math.gcd(i,g[0])
    return g
s=input().split()
e=Great_Gcd([int(i) for i in input().split()])
for _ in range(int(s[1])):
    k=int(input())
    if e[1] :
        print(e[0]+k)
    else:
        print(math.gcd(e[0],k))

    


