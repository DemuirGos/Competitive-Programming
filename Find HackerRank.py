import re
for _ in range(int(input())):
    s=input()
    if re.match("^hackerrank.+",s):
        print(1)
    elif re.match(".+hackerrank$",s):
        print(2)
    elif re.match("^hackerrank$",s):
        print(0)
    else :
        print(-1)


