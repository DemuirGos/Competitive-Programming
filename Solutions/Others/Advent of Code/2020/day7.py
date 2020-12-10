import sys
import re
m=dict((w[0][1],dict([i[::-1] for i in w[1:]])) for w in [re.findall("(\d+)? ?(\w+ \w+) bag",s) for s in open("InputData\day7.txt", "r").read().split('\n')])
def canHoldGold (s,k) :
    if k in s:
        return True
    def lookup(bags,cond):
        if len(bags)==0:
            return cond
        else:
            return lookup(bags[1:],bags[0] in m and cond|canHoldGold(m[bags[0]],k) or cond)
    return lookup(list(s.keys()),False)
def bagCanHold (k,s,size) :
    if len(s)==0 :
        return size
    else :
        return bagCanHold(k,s[1:],size + (s[0] != 'no other' and int(m[k][s[0]]) * ( 1 + bagCanHold(s[0],list(m[s[0]].keys()),0) or 0)))
part1=len([b for b in m if canHoldGold(m[b],"shiny gold")])
part2=bagCanHold("shiny gold","shiny gold" in m and list(m["shiny gold"].keys()) or [],0)  

