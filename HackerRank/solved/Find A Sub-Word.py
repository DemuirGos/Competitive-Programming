from re import *
s=""
q=[]
for _ in range(int(input())):
    s+=input()+"\n"
for _ in range(int(input())):
    print(len(findall("\w"+input()+"\w",s)))
