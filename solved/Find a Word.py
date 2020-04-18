import re
sentences=""
patterns=[]
for _ in range(int(input())):
    sentences+=input()+"\n"
for _ in range(int(input())):
    print(len(re.findall("(\\b|\W)"+input()+"(\\b|\W)",sentences)))
