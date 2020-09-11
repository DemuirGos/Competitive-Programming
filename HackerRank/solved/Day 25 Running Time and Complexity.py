import math
def prime(n):
    if n==1 or n==0:
        return 0
    if n%2==0:
        return n==2
    else:  
        for i in range(3,round(math.sqrt(n))+1):
            if n%i==0:
                return 0
        return 1
for _ in range(int(input())):
    if(prime(int(input()))):
        print('Prime')
    else:
        print('Not prime')
