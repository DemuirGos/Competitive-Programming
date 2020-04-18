import re
for _ in range(int(input())):
    if(re.match("^(9|7|8)[0-9]{9}$",input())):
        print("YES")
    else :
        print("NO")
