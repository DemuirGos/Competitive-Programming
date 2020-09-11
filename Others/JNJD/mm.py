l=[]

for _ in range(int(input())):

               l.append(input().split())

               l=sorted(l,key=lambda pat: [-int(pat[1]),int(pat[2]),pat[0]])

print(l)
