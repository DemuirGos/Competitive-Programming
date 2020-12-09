file="hashcode\\a_example.txt"
input=open(file,"r")
lines=input.readlines()
x = [int(i) for i in  lines[0].split()]
B = x[0]
L = x[1]
D = x[2]
library = {}
score = [int(i) for i in  lines[1].split()]
book = []
sol=[]
k=2
for i in range(L):
    library[i]=[int(j) for j in lines[k].split()]
    library[i].append([min(library[i][2]*(D-library[i][1]),library[i][0])])
    library=sorted(library,key= lambda l:l[int(len(l))-1])
    book.append(sorted([int(j) for j in lines[k+1].split()],key=lambda book:score[book],reverse=True))
    k+=2
for i in range(L):
    D-=library[i][1]
    newD=D
    sol_lib=[]
    while library[i][0]!=0 and D!=0 and newD!=0:
        Submit=min(library[i][0],library[i][2]*newD)
        sol_lib=sol_lib+book[i][:Submit]
        newD-=Submit*library[i][2]
        library[i][0]-=Submit
        if library[i][0]==0 or D==0 or newD==0:
            break
    sol.append(sol_lib)
    if D<=0 :
        break
def write_result(input):
    with open(input, 'w') as f:
        f.write(str(len(sol))+"\n")
        for i in range(len(sol)):
            f.write(str(sol[i][0]))
            f.write(" ")
            f.write(str(len(sol[i])))
            f.write("\n")
            for j in range(1,len(sol[i])):
                f.write(str(sol[i][j]))
                f.write(" ")
            f.write("\n")
write_result(file)
print(len(sol))
for i in range(len(sol)):
    print(sol[i][0],len(sol[i]))
    for j in range(1,len(sol[i])):
        print(sol[i][j],end=j==len(sol[i]) and "" or " ")
    print()

    


