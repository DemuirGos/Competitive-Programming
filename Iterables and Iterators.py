def bin(n,k):
    r=1
    if(n==k or k==0):
         return r
    for i in range(1,k+1):
        r*=(n+1-i)
        r=r//i
    return r
n=int(input())
count_a=0
s=input()
for _ in s:
    if(_=='a'):
        count_a+=1
k=int(input())
result=0
total_space=bin(n,k)
for i in range(1,k+1):
    result+=bin(n-count_a,k-i)*bin(count_a,i)
print(result/total_space)
