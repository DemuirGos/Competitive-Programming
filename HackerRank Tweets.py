import re
r=0
for _ in range(int(input())):
    if(re.findall("hackerrank",input(),flags=re.IGNORECASE|re.VERBOSE)):
        r+=1
print(r)

