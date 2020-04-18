import math
n=input()
a=[int(i) for i in input().split()]
m=sum(a)/len(a)
sig=0
for i in range(len(a)):
    sig+=(a[i]-m)**2/len(a)
print(math.sqrt(sig))
