import pprint
import itertools
from math import sqrt
def getEdges(grid):
    return [grid[0],[i[-1] for i in grid],grid[-1],[i[0] for i in grid]]
def pivot(grid,i):
    if i == 0 :
        return grid
    else:
        return [grid[0][::-1],grid[-1],grid[2][::-1],grid[1]]
def rotate(grid,i):
    return [grid[(j+i)%4] for j in range(len(grid))]
#strin={int(j[0][5:-1]):[config for piv in [rotate(c) for c in pivot([''.join(['1' if c=='#' else '0' for c in l]) for l in getEdges(j[1:])])] for config in piv] for j in [i.split('\n') for i in """Tile 3557:
strin=[(int(j[0][5:-1]),[''.join(['1' if c=='#' else '0' for c in l]) for l in getEdges(j[1:])]) for j in [i.split('\n') for i in """Tile 2311:
..##.#..#.
##..#.....
#...##..#.
####.#...#
##.##.###.
##...#.###
.#.#.#..##
..#....#..
###...#.#.
..###..###

Tile 1951:
#.##...##.
#.####...#
.....#..##
#...######
.##.#....#
.###.#####
###.##.##.
.###....#.
..#.#..#.#
#...##.#..

Tile 1427:
###.##.#..
.#..#.##..
.#.##.#..#
#.#.#.##.#
....#...##
...##..##.
...#.#####
.#.####.#.
..#..###.#
..##.#..#.

Tile 2729:
...#.#.#.#
####.#....
..#.#.....
....#..#.#
.##..##.#.
.#.####...
####.#.#..
##.####...
##..#.##..
#.##...##.""".split('\n\n')]]
#initial = [[[]]*int(sqrt(len(strin))) for i in range(int(sqrt(len(strin))))]
# grid = (i,j) -> (img,piv,rot)
# img = [top,right,bottom,left] (1,0) (0,1) (-1,0) (0,-1)
def findNextCellToFill(lim, i, j):
    if j == lim:
        return [i+1,0]
def Validate(grid,i,j,piece):
    index = {(-1,0):(0,2), (1,0):(2,0), (0,-1):(3,1), (0,1):(1,3)}
    b=[grid[(i + p[0][0], j + p[0][1])][0][p[1][1]]==piece[p[1][0]] if (i + p[0][0],j + p[0][1]) in grid else True for p in index.items()]
    return all(b)
def solve(grid,i,j,pieces,lim):
    if j == lim:
        i,j = i+1,0
    if len(pieces)==0 or i==lim:
        pprint.pprint(grid)
        return True
    for piece in pieces:
        for piv in range(2):
            for rot in range(4):
                updatedImage = rotate(pivot(piece[1],piv),rot)
                if Validate(grid,i,j,updatedImage):
                    grid[(i,j)] = (updatedImage, piece[0])
                    if solve(grid,i,j+1,[p for p in pieces if piece!=p],lim):
                        return True
                    grid.pop((i,j))
    return False
pprint.pprint(solve({},0,0,strin,3))

