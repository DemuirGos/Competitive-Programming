import math
def lcm(a,b):
    return round((a*b)/math.gcd(a,b))
for _ in range(int(input())):
    n=int(input())
    s=[int(i) for i in input().split()]
    start = True
    end=False
    for i in range(n):
        if i == 0:
            print(lcm(s[i],s[i]),end=' ')
        if i!=n-1:
            print(lcm(s[i],s[i+1]),end=' ')
        else:
            print(lcm(s[i],s[i]),end=' ')
    print()
