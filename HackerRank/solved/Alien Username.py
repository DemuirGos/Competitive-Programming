import re
for i in range(int(input())):
    if re.match("^(_|\.)\d+(0|[a-zA-Z]*(_?))$",input()):
        print("VALID")
    else:
        print("INVALID")
