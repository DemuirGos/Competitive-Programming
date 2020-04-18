n=input()
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
for i in range(len(b)):
    a[i]*=b[i]
print(round(sum(a)/sum(b),1))

