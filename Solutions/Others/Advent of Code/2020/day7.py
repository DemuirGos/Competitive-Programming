import sys
import itertools
import re
m=dict((w[0][1],dict([i[::-1] for i in w[1:]])) for w in [re.findall("(\d+)? ?(\w+ \w+) bag",s) for s in open("InputData\day7.txt", "r").read().split('\n')])
d={'flatten':lambda l,r:d['flatten'](sum([i for i in l if type(i)!=str],[]),r+[i for i in l if type(i)==str]) if len(l)!=0 else set(r)}
def WayUpWeGo (s,k) :
    return [[b,WayUpWeGo(m,b)] for b in s if k in m[b]]
def WayDownWeGo (k,s,size) :
    if len(s)==0 :
        return size
    else :
        return WayDownWeGo(k,s[1:],size + (s[0] != 'no other' and int(m[k][s[0]]) * ( 1 + WayDownWeGo(s[0],list(m[s[0]].keys()),0) or 0)))
part1=len(d['flatten'](sum([[b,list(itertools.chain(*WayUpWeGo(m,b)))] for b in m if "shiny gold" in m[b]],[]),[]))
part2=WayDownWeGo("shiny gold","shiny gold" in m and list(m["shiny gold"].keys()) or [],0) 
