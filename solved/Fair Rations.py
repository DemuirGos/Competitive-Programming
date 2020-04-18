n= int(input())
citizens=[int(i)%2 for i in input().split()]
c_1 = citizens.count(1)
if c_1%2==1:
    print("NO")
else :
    loafs = 0
    last = -1
    for i in range(len(citizens)):
        if citizens[i]==1 and last==-1:
            last=i
        elif citizens[i]==1 and last!=-1:
            loafs+=+ 2*(i-last)
            last=-1
    print(loafs)
    
