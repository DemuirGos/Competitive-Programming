import numpy
from itertools import product
from functools import reduce
from math import sqrt
Edges = lambda grid:[grid[0],[i[-1] for i in grid],grid[-1],[i[0] for i in grid]]
strin=[(int(j[0][5:-1]),j[1:]) for j in [i.split('\n') for i in open("InputData\day20.txt", "r").read().split('\n\n')]]
def solve(pieces,lim,grid = {},i = 0,j = 0):
    pivot = lambda grid,i: grid if i == 0 else [grid[2],grid[1][::-1],grid[0],grid[3][::-1]]
    rotate= lambda grid,i: grid if i == 0 else rotate([grid[3][::-1],grid[0],grid[1][::-1],grid[2]],i-1)
    Validate = lambda grid,i,j,piece: all([grid[(i + p[0], j + p[1])][0][img[0]]==piece[img[1]] if (i + p[0],j + p[1]) in grid else True for p,img in [((-1,0),(2,0)), ((0,-1),(1,3))]])
    def engine(pieces,lim,grid = {},i = 0,j = 0):
        if len(pieces) == 0:
            return (True,grid)
        j,i = j%lim,i + j // lim
        for piece in pieces:
            for piv,rot in [(y,x) for y in range(2) for x in range(4)]:
                    updatedImage = rotate(pivot(piece[1],piv),rot)
                    if Validate(grid,i,j,updatedImage):
                        grid[(i,j)] = (updatedImage, (piece[0],piv,rot))
                        if engine([p for p in pieces if piece!=p],lim,grid,i,j+1) != False:
                            return (True,grid)
                        grid.pop((i,j))
        return False
    return engine(pieces,lim,grid,i,j)
def search(grid,pieces):
    def transform(img, config=(0,0), onion = True):
        rotate = lambda image,i : image if i==0 else rotate(list(zip(*image[::-1])),i-1)
        pivot  = lambda image,i : image if i == 0 else image[::-1]
        peel   = lambda image   : [list(l)[1:-1] for l in image[1:-1]]
        return (lambda r,o: r if o == False else peel(r))(rotate(pivot(img,config[0]),config[1]),onion)
    def construct(Map):
        return (lambda grid: ["".join(l) for l in numpy.bmat([[grid[i,j] for j in range(int(sqrt(len(grid))))] for i in range(int(sqrt(len(grid))))]).tolist()])({id:transform(Map[id][1][1],Map[id][1][2],pieces[Map[id][1][0]]) for id in Map})
    def HideSeek(grid,pattern):
        def extract(i,j,image,pattern):
            portion =  [[image[i + l][w + j] for w in range(len(pattern[0]))] for l in range(len(pattern))]
            return all([portion[n][k] == pattern[n][k] for n in range(len(pattern)) for k in range(len(pattern[0])) if pattern[n][k]=='#'])
        def seek(grid,configuration,dragons=0):
            if len(configuration) == 0:
                return sum([l.count('#') for l in grid]) - dragons*sum([l.count('#') for l in pattern])
            else:
                image = transform(grid, configuration[0], onion = False)
                return seek(configuration[1:],sum([1 for i in range(len(image)-len(pattern)) for j in range(len(image[0])-len(pattern[0])) if extract(i,j,image,pattern)]))
        return seek(grid,[(y,x) for y in range(2) for x in range(4)])
    return HideSeek(construct(grid),[list(i) for i in ["                  # ","#    ##    ##    ###"," #  #  #  #  #  #   "]])
part1 = (lambda r: reduce(lambda x,y:x*y,[int(r[i][1][0]) for i in product([0,int(sqrt(len(strin)))-1], repeat=2)]))(solve([(id,[''.join(l) for l in Edges(p)]) for id,p in strin],int(sqrt(len(strin))))[1])
part2 = (lambda c,t:t - c) (*search(solve([(id,[''.join(l) for l in Edges(p)]) for id,p in strin],int(sqrt(len(strin))))[1],dict(strin)))
<<<<<<< Updated upstream
=======
print(part1,part2)
>>>>>>> Stashed changes
