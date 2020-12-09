from functools import reduce
strin=open("InputData\day6.txt", "r").read().split('\n\n')
part1=sum([len(set(i.replace('\n',''))) for i in strin])
part2=sum([len(reduce(lambda x,y:x.intersection(y),[set(j) for j in i.split('\n')])) for i in strin])
