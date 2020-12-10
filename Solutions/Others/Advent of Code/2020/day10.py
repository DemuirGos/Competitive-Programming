from itertools import permutations
from functools import reduce
strin=list(set(map(int,open("InputData\day10.txt", "r").read().split('\n'))))
def part1diff(s,v,l,stp,m,r,fun):
    for i in stp:
        if s+i in l:
            m.append(s)
            r.append(i)
            l.remove(s+i)
            return part1diff(s+i,v,l,stp,m,r,fun)
    return fun(r,l,m)
def part2path(v,d,stp,fun):
    print(d)
    for adapter in d :
        for step in stp:
            if adapter + step in d:
                d[adapter+step]+=d[adapter]
    return fun(v,d,stp,fun)
part1=part1diff(0,max(strin)+3,[0]+strin.copy()+[max(strin)+3],[1,2,3],[],[],lambda r,l,m:r.count(1)*r.count(3))
part2=part2path(max(strin)+3,dict(map(lambda x:(x,x==0 and 1 or 0),[0]+strin.copy()+[max(strin)+3])),[1,2,3],lambda v,d,stp,fun:d[v])
