from operator import mul
from functools import reduce
strin = open("InputData\day3.txt", "r").read()
def move(it,stps,carte,c):
    x,y=(it*stps[0])%len(carte[0]),it*stps[1]
    if y >= len(carte):
        return c
    elif carte[y][x]=='#':
        c += 1
    return move(it+1,stps,carte,c)
part1 = reduce(mul,[move(0,i,strin.split('\n'),0)for i in [(3,1)]])
part2 = reduce(mul,[move(0,i,strin.split('\n'),0)for i in [(1,1),(3,1),(5,1),(7,1),(1,2)]])
