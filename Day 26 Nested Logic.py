def f(b,a):
    a=[int(i) for i in a.split()]
    b=[int(i) for i in b.split()]
    if(b[2]+1==a[2] and a[0]==1 and a[1]==1):
        a[2]=b[2]
        a[1]=12
        a[0]=31
    if(a[2]<b[2]):
        return 10000
    elif a[2]==b[2]:
        if(a[1]<b[1]):
            return (b[1]-a[1])*500
        else:
            if(a[0]<b[0]):
                return (b[0]-a[0])*15
            else:
                return 0
    else:
        return 0
print(f(input(),input()))
