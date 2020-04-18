import re
pattern="[a-zA-Z](\w|-|\.|_)+@[a-zA-Z]+\.[a-zA-Z]{1,3}$"
for _ in range(int(input())):
    s=input().split()
    if re.match(pattern,s[1][1:len(s[1])-1]):
        print (" ".join(s))
