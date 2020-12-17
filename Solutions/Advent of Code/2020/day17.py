import itertools
lines=open("InputData\day17.txt", "r").read().split('\n')
count = lambda offs,grid,point:sum([1 for offset in offs if tuple(map(lambda x:x[0]+x[1],zip(point,offset))) in grid])
coord = lambda h,w,d,c,dim: (lambda l:l if dim == 3 else [(i,j,k,s) for s in range(-c,h+c) for i,j,k in l])([(x,y,z) for z in range(-c,h+c) for y in range(-c,w+c) for x in range(-c,d+c)])
def proc(strin,dim):
    offsets = [i for i in list(itertools.product([-1,0,1],repeat=dim)) if i!=tuple([0]*dim)]
    inpt = [(i,j,0,0) for j in range(len(strin)) for i in range(len(strin[0])) if strin[j][i]=="#"]
    def engine(old,cycle,lim,dim):
        print(cycle)
        if cycle==lim:
            return old
        else:
            return engine([i for i in coord(1,len(strin),len(strin[0]),cycle,dim) if (i in old and 2<= count(offsets,old,i) <=3) or (i not in old and count(offsets,old,i)==3)],cycle+1,lim,dim)
    return len(engine(list(map(lambda x:x[:dim],inpt)),1,7,dim))
part1 = proc(lines,3)
part2 = proc(lines,4)
