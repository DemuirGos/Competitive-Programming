from math import ceil,gcd
from functools import reduce
strin=[[(int(w),idx) for idx,w in enumerate(l.split(',')) if w!='x'] for l in open("InputData\day13.txt", "r").read().split('\n')]
def RemainderCalculator(prt2):
    def Inverse(init, newt,newr, t, r):
        if newr==0:
            return t if t>=0 else t + init
        else:
            quotient = r // newr
            return Inverse(init, t - quotient * newt, r - quotient * newr, newt,newr)
    Ids = list(map(lambda x:x[0],prt2))
    idx = list(map(lambda x:(x[0]-x[1])%x[0],prt2))
    n   = reduce(lambda x,y:x*y,Ids)
    yi  = list(map(lambda x:n//x,Ids))
    zi  = list(map(lambda x:Inverse(x[1],gcd(x[0],x[1]),x[0],0,x[1])%x[0],list(zip(yi,Ids))))
    return  reduce(lambda x,y:x+y,list(map(lambda x:x[0]*x[1]*x[2],list(zip(idx,yi,zi)))))%n
part1 = (lambda x:(x[1][0][1]-x[0][0])*x[1][0][0])([strin[0][0],sorted([(x,ceil(strin[0][0][0]/x)*x,(ceil(strin[0][0][0]/x)*x)%strin[0][0][0],strin[1][0]) for x,i in strin[1]],key=lambda x:x[2])])
part2 = RemainderCalculator(strin[1])
