import re
s=""
for _ in range(int(input())):
    s+=input()+"\n"
for _ in range(int(input())):
    word=input()
    print(len(re.findall(word[:len(word)-2]+"(s|z)e",s)))
