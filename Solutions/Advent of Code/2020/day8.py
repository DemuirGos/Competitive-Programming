import sys
op={"nop":(lambda x,y,_: (y + 1,x)),
    "acc":(lambda x,y,v: (y + 1,x + v)),
    "jmp":(lambda x,y,v: (y + v,x))}
inlist=[[k[0],int(k[1])] for k in [i.split() for i in open("InputData\day8.txt", "r").read().split("\n")]]
def tryFix2(codes,ptr,isCompleted):
    return isCompleted[1] if isCompleted[0] else tryFix2(inlist.copy(),ptr+1,isCompleted if codes[ptr][0]=="acc" else process(codes[:ptr] + [["nop" if codes[ptr][0]=="jmp" else "jmp" if codes[ptr][0]=="nop" else codes[ptr][0],codes[ptr][1]]] + codes[ptr+1:],(0,0),[]))
def process (codes,pcc,ran):
    return (True,pcc[1]) if pcc[0] == len(codes) else (False,pcc[1]) if pcc[0] in ran else process(codes,op[codes[pcc[0]][0]](pcc[1],pcc[0],codes[pcc[0]][1]),ran+[pcc[0]])
part1=process(inlist,(0,0),[])[1]
part2=tryFix2(inlist.copy(),0,(False,0))

