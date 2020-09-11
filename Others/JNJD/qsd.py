from math import *
n=int(input())
s=0
f=0
for i in range(n+1):
    lol=i*(i+1)/2
    if(lol>=n):
        print(lol)
        s=(lol-n>0) and lol-n or 1
        f=(i>0) and i or 1
        break
print(int(s),f)
    
