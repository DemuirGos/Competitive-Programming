import re
inpt = open("InputData/day24.txt",'r').readlines()
directions = {'nw':(-1/2,1.0),'ne':(1/2,1.0),'sw':(-1/2,-1.0),'se':(1/2,-1.0),'e':(1.0,0.0),'w':(-1.0,0.0)}
format = lambda s:re.findall("((?:se)|(?:ne)|(?:sw)|(?:nw)|(?:e)|(?:w))",s)
process = lambda position,direction: position if len(direction)==0 else process(tuple(p + q for p, q in zip(position, directions[direction[0]])),direction[1:])
count = lambda offs,grid,point:sum([grid.get(tuple(map(lambda x:x[0]+x[1],zip(point,offset))),0) for offset in offs])
BlackWhite = (lambda r :{i:r.count(i)%2 for i in list(dict.fromkeys(r))})([process((0,0),format(l)) for l in inpt])
Neighbors = lambda o,p,g :(lambda r:[point for point in r if point not in g] + [p])([tuple(c + o for c, o in zip(p, offset)) for offset in o ])
process = lambda grid,offsets,cycle : list(grid.values()).count(1) if cycle == 0 else process({i:(0 if (grid.get(i,0) == 1 and not(0 < count(offsets,grid,i) <= 2)) else 1 if (grid.get(i,0) == 0 and count(offsets,grid,i) == 2) else grid.get(i,0)) for j in grid for i in Neighbors(offsets,j,grid)},offsets,cycle-1)
part1 = [BlackWhite[i] for i in BlackWhite].count(1)
part2 = process(BlackWhite,directions.values(), 100)