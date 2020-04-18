import re
s=""
for _ in range(int(input())):
    s+=input()+" "
print(";".join(sorted(list(set(re.findall("[\w\.]+@[\w\.]+\w+",s))))))
