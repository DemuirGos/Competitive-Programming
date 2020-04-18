import re
for _ in range(int(input())):
    if(re.match("^[A-Z]{5}\d{4}[A-Z]$",input())):
        print("YES")
    else :
        print("NO")
