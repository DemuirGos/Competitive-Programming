import math
p=[2]
k=3
def gen(n,k):
    while(len(p)<n):
        b=True
        if(k%2==0):
            b=False
        else:
            for j in range(3,int(math.sqrt(k)+1),2):
                if k%j==0:
                    b=False
        if b and k not in p:
            p.append(k)
        k+=2
def sum(n):
    s=n*(n+1)/2
    return s
def subs(s):
    #generate subset of p
    #multiply elem of susbet 
    #perform sum
    #perform sum of the sums
    for i in range(1<<(len(s)-1)+1):
        
for _ in range(int(input())):
    m,a=[int(i) for i in input().split()]
    gen(m,k)
    print(p[:m])
