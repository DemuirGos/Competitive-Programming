import math
n=float(input())
k=float(input())
print(round(math.exp(-n)*pow(n,k)/math.factorial(k),3))
