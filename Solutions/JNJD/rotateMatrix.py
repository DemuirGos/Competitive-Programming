def rotate(m):
    n=len(m)
    l=[]
    for i in range(n):
        for j in range(n-1,-1,-1):
            print(m[j][i],end=' ')
        print()
n = int(input())
matrix = [list(map(int, input().split())) for i in range(n)]
rotate(matrix)
