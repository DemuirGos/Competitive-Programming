L=[]
for _ in range(int(input())):
    L.append([int(i) for i in input().split()][::-1])
L.sort()
taxi = [0]

for l in L:
    taxi.sort()
    taxi=taxi[::-1]
    busy = 1
    for t in range(len(taxi)):
        if taxi[t]<l[0]:
            taxi[t]=l[0]+abs(l[1]-l[3])+abs(l[2]-l[4])
            busy = 0
            break
    if busy == 1 :
        taxi.append(l[0]+abs(l[1]-l[3])+abs(l[2]-l[4]))
    
print(len(taxi))
