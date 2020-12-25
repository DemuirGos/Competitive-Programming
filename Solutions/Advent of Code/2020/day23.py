from functools import reduce
strin = [int(i) for i in list("0" + open("InputData/day24.txt",'r').read())]
chain = lambda c : {c[i]:c[1] if  i + 1 >= len(c) else c[i+1] for i in range(len(c))}
def solve(chain,start,idx,max,cond):
    while idx != 0:
        curr = chain[start]
        neighbors = [chain[curr],chain[chain[curr]],chain[chain[chain[curr]]]]
        dest = curr - 1 or max
        while dest in neighbors:
            dest = dest - 1 or max
        chain[curr],chain[dest],chain[neighbors[2]],idx,start = chain[neighbors[2]],neighbors[0],chain[dest],idx-1,chain[start]
    else:
        result = lambda chains,start,pred,rslt:rslt if pred(start,rslt) else result(chains,chains[start],pred,rslt + [start])
        return result(chain,chain[1],cond,[])
part1 = "".join([str(v) for v in solve(chain(strin), 0, 100, max(strin), cond=lambda idx,_ : idx == 1)])
part2 = reduce(lambda x,y:x*y,solve(chain(strin + list(range(10,1000001))), 0, 10000000, 1000000, cond=lambda _,rslt : len(rslt)==2))