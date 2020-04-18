import math
for _ in range(int(input())):
    a=[int(i) for i in input().split()]
    n=a[0]
    k=a[1]
    delta=n*(n-4*k)
    if delta < 0:
        print(n-1)
    else:
        x1=(n-math.sqrt(delta))/2
        print(math.floor(math.ceil(x1)))
