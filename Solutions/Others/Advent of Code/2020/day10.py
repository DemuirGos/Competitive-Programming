strin=list(set(map(int,open("InputData\day10.txt", "r").read().split('\n'))))
def part1diff(s,v,l,stp,m,r,fun):
    for i in stp:
        if s+i in l:
            return part1diff(s+i,v,l[l.index(s+i):]+l[:l.index(s+i)+1],stp,m+[s],r+[i],fun)
    return fun(s,v,l,stp,m,r)
def part2path(v,d,stp,update):
    return max([update(v,d,adapter,step) for adapter in d for step in stp if adapter + step in d])
part1=part1diff(0,max(strin)+3,[0]+strin.copy()+[max(strin)+3],[1,2,3],[],[],lambda s,v,l,stp,m,r:r.count(1)*r.count(3))
part2=part2path(max(strin)+3,dict(map(lambda x:(x,x==0 and 1 or 0),[0]+strin.copy()+[max(strin)+3])),[1,2,3],lambda v,d,adapter,step:d.update({adapter+step:d[adapter+step]+d[adapter]}) or d[v])
