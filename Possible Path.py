import math
for _ in range(int(input())):   
    s=input().split()
    if(math.gcd(int(s[2]),int(s[3]))==math.gcd(int(s[1]),int(s[0]))):
        print("YES")
    else :
        print("NO")
