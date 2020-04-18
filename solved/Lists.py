L=[]
for _ in range(int(input())):
    l=input().split()
    if l[0]=='insert':
        L.insert(int(l[1]),int(l[2]))
    elif l[0]=='append':
        L.append(int(l[1]))
    elif l[0]=='remove':
        L.remove(int(l[1]))
    elif l[0]=='sort':
        L.sort()
    elif l[0]=='pop':
        L.pop()
    elif l[0]=='reverse':
        L.reverse()
    elif l[0]=='print':
        print(L)


