x,y,z,n=(int(input()) for i in range(4))
l=[]
for i in range(x+1):
    for j in range(y+1):
        for k in range(z+1):
            if(i+j+k!=n):
                l.append([i,j,k])
print(l)

