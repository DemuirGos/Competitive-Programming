m={}
for i in range(10):
    m[i]=0
s=input()
prev=s[0]
m[int(prev)]+=1
if(len(s)==1):
    print("("+str(m[int(s[0])])+", "+s[0]+")",end=' ')
for i in range(1,len(s)):
    if(s[i]==prev):
        m[int(s[i])]+=1
    else :
        print("("+str(m[int(s[i-1])])+", "+s[i-1]+")",end=' ')
        prev=s[i]
        m[int(s[i-1])]=0
        m[int(s[i])]+=1
    if(i==len(s)-1):
        print("("+str(m[int(s[i])])+", "+s[i]+")",end=' ')


