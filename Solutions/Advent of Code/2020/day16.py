import re
from functools import reduce
strin=open("InputData\day16.txt", "r").read().split('\n\n')
ranges=[r for m in re.findall("(?:\w+)+:(\d+)-(\d+)or(\d+)-(\d+)",strin[0].replace(' ','')) for r in [list(range(int(m[0]),int(m[1])+1)),list(range(int(m[2]),int(m[3])+1))]]
ticket=[int(i) for i in  strin[1].split('\n')[1].split(',')]
neighbors=[[int(i) for i in t.split(',')] for t in  strin[2].split('\n') [1:]]
Valids=[ticket]+[t for t in neighbors if all([any([n in r for r in ranges]) for n in t])]
def proc(matrix,_ranges):
    d = sorted(enumerate([[j for j in range(len(matrix)) if all([n in _ranges[r] for n in matrix[j]])] for r in range(len(_ranges))]),key=lambda l:len(l[1]))
    def Filter(dic,res):
        if len(dic)!=0:
            return Filter([(i,[j for j in v if all([j not in r for _,r in res])]) for i,v in dic if len(v)!=1],res+[(i,v) for i,v in dic if len(v)==1])
        else:
            return list(map(lambda x:x[1][0],sorted(res,key=lambda n:n[0]))) 
    return Filter([(i,v) for i,v in d if len(v)!=1],[(i,v) for i,v in d if len(v)==1])
part1 = sum([n for t in neighbors for n in t if all([n not in r for r in ranges])])
part2 = reduce(lambda i,j:i*j,[ticket[idx] for idx in proc(list(zip(*Valids)),[set(ranges[i]).union(set(ranges[i+1])) for i in range(0,len(ranges)-1,2)])[:6]])
