import re
for _ in range(int(input())):
    s=input()
    if re.match("^(H|h)(I|i)\s[^Dd]",s):
        print(s)
