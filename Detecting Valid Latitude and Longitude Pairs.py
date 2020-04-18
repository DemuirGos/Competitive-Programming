import re
for _ in range(int(input())):
    if re.match("^\((\+?|-)(([0-9]|([1-8][0-9]))(\.\d+)?|(90(.0+)?)), (\+?|-)(([0-9]|([1-9][0-9])|(1[0-7][0-9]))(\.\d+)?|(180(.0+)?))\)$",input()):
        print("Valid")
    else:
        print("Invalid")
