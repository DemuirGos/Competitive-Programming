import re
for _ in range(int(input())):
    if(re.match("^[a-z]{0,3}\d{2,8}[A-Z]{3,}$",input())):
        print("VALID")
    else:
        print("INVALID")
