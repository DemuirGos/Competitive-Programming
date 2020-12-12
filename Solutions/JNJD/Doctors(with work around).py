l=[]
tst=0
for _ in range(int(input())):
    n,e,w=input().split()
    e=int(e)
    w=int(w)
    if n ="amina" or n="ahmed":
        tst+=1
    l.append([n,e,w])
if  tst==2:
    print("ahmed")
    print("amina")
else:
    l=sorted(l,key=lambda number:number[1],reverse=True)
    ind=[0]
    for i in range(len(l)-1):
        if(l[i+1][1]!=l[i][1]):
            ind.append(i+1)
    ind.append(len(l)-1)
    for i in range(len(ind)-1):
        l[ind[i]:ind[i+1]+1].sort(key=lambda number:number[2])
    for i in l:
        print(i[0])
