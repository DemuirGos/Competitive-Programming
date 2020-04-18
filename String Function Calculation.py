import re
lst=[]
dic={}
def subString(Str): 
    for Len in range(1,len(Str) + 1): 
        for i in range(len(Str) - Len + 1):
            s="" 
            j = i + Len - 1
            for k in range(i,j + 1): 
                s+=Str[k]
            if not s in dic:
                lst.append(s)
                dic[s]=1
def f(s):
    st =[]
    r=0
    for i in lst :
        st=re.findall("(?=("+i+"))",s)
        r=max(r,len(st)*len(i))
    print(r)

s=input()
subString(s)
f(s)
