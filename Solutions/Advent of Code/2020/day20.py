from pprint import pprint
import numpy
from itertools import product
from functools import reduce
from math import sqrt
Edges = lambda grid:[grid[0],[i[-1] for i in grid],grid[-1],[i[0] for i in grid]]
pivot = lambda grid,i: grid if i == 0 else [grid[2],grid[1][::-1],grid[0],grid[3][::-1]]
rotate= lambda grid,i: grid if i == 0 else rotate([grid[3][::-1],grid[0],grid[1][::-1],grid[2]],i-1)
strin=[(int(j[0][5:-1]),j[1:]) for j in [i.split('\n') for i in open("InputData\day20.txt", "r").read().split('\n\n')]]
def solve(pieces,lim,grid = {},i = 0,j = 0):
    def Validate(grid,i,j,piece):
        return all([grid[(i + p[0], j + p[1])][0][img[0]]==piece[img[1]] if (i + p[0],j + p[1]) in grid else True for p,img in [((-1,0),(2,0)), ((0,-1),(1,3))]])
    if len(pieces) == 0:
        return (True,grid)
    j,i = j%lim,i + j // lim
    for piece in pieces:
        for piv,rot in [(y,x) for y in range(2) for x in range(4)]:
                updatedImage = rotate(pivot(piece[1],piv),rot)
                if Validate(grid,i,j,updatedImage):
                    grid[(i,j)] = (updatedImage, (piece[0],piv,rot))
                    if solve([p for p in pieces if piece!=p],lim,grid,i,j+1) != False:
                        return (True,grid)
                    grid.pop((i,j))
    return False
def search(grid,pieces):
    def transform(piv,rot,img,onion = True):
        def rotate(image,i):
            if i == 0:
                return image
            else:
                return rotate(list(zip(*image[::-1])),i-1)
        def pivot(image,i):
            if i == 0:
                return image
            else :
                return image[::-1]
        def peel(image):
            return [list(l)[1:-1] for l in image[1:-1]]
        result = rotate(pivot(img,piv),rot)
        return result if onion == False else peel(result)
    def construct(grid):
        return ["".join(l) for l in numpy.bmat([[grid[i,j] for j in range(int(sqrt(len(grid))))] for i in range(int(sqrt(len(grid))))]).tolist()]
    def PieceWise(Map):
        for id in Map:
            Map[id]= transform(Map[id][1][1],Map[id][1][2],pieces[Map[id][1][0]])
        return Map
    def HideSeek(grid,pattern):
        def extract(i,j,image,pattern):
            portion =  [[image[i + l][w + j] for w in range(len(pattern[0]))] for l in range(len(pattern))]
            return all([portion[n][k] == pattern[n][k] for n in range(len(pattern)) for k in range(len(pattern[0])) if pattern[n][k]=='#'])
        r = []
        for piv,rot in [(y,x) for y in range(2) for x in range(4)]:
            c=0
            image = transform(piv, rot, grid, onion = False)
            for i in range(len(image)-len(pattern)):
                for j in range(len(image[0])-len(pattern[0])):
                    c += 1 if extract(i,j,image,pattern) else 0
            r+=[(c*sum([l.count('#') for l in pattern]),sum([l.count('#') for l in image]))]
        return sorted(r,key = lambda x:x[0],reverse=True)[0]
    return HideSeek(construct(PieceWise(grid)),[list(i) for i in ["                  # ","#    ##    ##    ###"," #  #  #  #  #  #   "]])
part1 = (lambda r: reduce(lambda x,y:x*y,[int(r[i][1][0]) for i in product([0,int(sqrt(len(strin)))-1], repeat=2)]))(solve([(id,[''.join(l) for l in Edges(p)]) for id,p in strin],int(sqrt(len(strin))))[1])
part2 = (lambda c,t:t - c) (*search(solve([(id,[''.join(l) for l in Edges(p)]) for id,p in strin],int(sqrt(len(strin))))[1],dict(strin)))