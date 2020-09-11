from math import *
m=10**9+7
for _ in range(int(input())):
    i=int(input())
    if i%20==0:
        i=(42*(i//20)-2)
    else:
        i=(42*(i//20)+2*(i%20))
    print(i%m)
    
