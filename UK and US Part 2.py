import re
text=""
for _ in range(int(input())):
    text+=input()+"\n"
for _ in range(int(input())):
    print(len(re.findall("\\b"+re.sub("ou","ou?",input())+"\\b",text)))

