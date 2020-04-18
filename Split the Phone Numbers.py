import re
for _ in range(int(input())):
    s=re.split("(-| )",input())
    print("CountryCode="+s[0]+",LocalAreaCode="+s[2]+",Number="+s[4])

