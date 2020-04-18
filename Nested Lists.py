L=[]
for _ in range(int(input())):
    L.append([input(),float(input())])
L.sort()
L.sort(key = lambda x: x[1])
temp=0
b=False
for i in range(len(L)):
    if(L[i][1]==L[0][1]):
        continue
    else :
        if(b and L[i][1]!=temp):
            break;
        print(L[i][0])
        temp=L[i][1]
        b=True
        

