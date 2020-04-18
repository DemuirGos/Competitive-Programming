import math
for _ in range(int(input())):
    n=int(input())
    m=(math.sqrt(1+8*n)-1)/2
    if m==round(m):
        print("Go On Bob",round(m),sep=' ',end='\n')
    else:
        print("Better Luck Next Time")
