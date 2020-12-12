from operator import mul
from functools import reduce
strin=open("InputData\day1.txt", "r").read()
part1=reduce(mul,[t for t in [(i,j) for i in [int(v) for v in strin.split()] for j in [int(v) for v in strin.split()]] if t[0]+t[1]==2020][0])
part2=reduce(mul,[t for t in [(i,j,n) for i in [int(v) for v in strin.split()] for n in [int(v) for v in strin.split()] for j in [int(v) for v in strin.split()]] if t[0]+t[1]+t[2]==2020][0])
