import sys
import re
strin = open("InputData\day7.txt", "r").read()
m={}
p={}
r={}
for s in strin.split('\n'):
    matches = re.findall("(\d+)? ?(\w+ \w+) bag",s)
    m[matches[0][1]] = dict([i[::-1] for i in matches[1:]])

def canHoldGold (s,k) :
    if k in s:
        return True
    val = False
    for bag in s:
        if bag in p:
            val |= p[bag]
        else:
            if bag in m:
                p[bag]=canHoldGold(m[bag],k)
            else:
                p[bag]=False
            val |= p[bag]
    return val
def bagCanHold (k) :
    if k in r :
        return r[k]
    size=0
    for bagTuple in m[k]:
        if(bagTuple == 'no other'):
            continue
        size+=int(m[k][bagTuple]) + int(m[k][bagTuple])*bagCanHold(bagTuple)
    r[k]=size
    return r[k]
part1=len([b for b in m if canHoldGold(m[b],"shiny gold")])
part2=bagCanHold("shiny gold")  
print(part1,part2)
