import re
name=[]
for _ in range(int(input())):
    s=input().split()
    if(re.match("^.+@gmail\.com$",s[1])):
        name.append(s[0])
name.sort()
print("\n".join(name))
