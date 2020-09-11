import math
p=[1]*10**8
def gen():
    for i in range(len(p)):
        if p[i]==1:
            for j in range(p[i],len(p),p[i]):
                p[i]==0
def solve():
    for _ in range(int(input())):
        gen()
        n=int(input())
        np=0
        for i in range(int(math.sqrt(n+1))):
            print(i)
            if(n%i==0):
                np+=p[i]+p[int(n/i)]
            if(np%2==0):
               print('B')
            else:
                print('A')
               
solve()
