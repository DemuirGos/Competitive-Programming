import re
for _ in range(int(input())):
    n=input()
    s=input().split()
    m="".join(["("+i+")?" for i in s])
    code=input()
    matches=re.findall(m,code)
    for i in s:
        code=re.sub(r''+i,"",code)
    if code!="":
        print("WRONG PASSWORD")
    else:
        r=""
        for i in matches:
            for j in i:
                if j!="":
                    r+=j.strip()+" "
        print(r.strip())
