import re

strin=open("InputData\day2.txt", "r").read()
part1 = [l for l in [(list(map(int,p[0].split('-'))),p[1][0],p[2]) for p in [w.split() for w in [s for s in strin.split('\n')]]] if l[0][0]<= l[2].count(l[1])<= l[0][1]]
part2 = [l for l in [(list(map(int,p[0].split('-'))),p[1][0],p[2]) for p in [w.split() for w in [s for s in strin.split('\n')]]] if (l[2][l[0][0]-1]==l[1] or l[2][l[0][1]-1]==l[1]) and l[2][l[0][0]-1] != l[2][l[0][1]-1]]
