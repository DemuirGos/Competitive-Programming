import sys
strin=open("InputData\day8.txt", "r").read()
op={"nop":(lambda x,y,v: (x , y + 1)),
    "acc":(lambda x,y,v: (x + v , y + 1)),
    "jmp":(lambda x,y,v: (x , y + v))
    }
inlist=[[k[0],int(k[1])] for k in [i.split() for i in strin.split("\n")]]
def tryFix(codes,ptr):
    completed=False
    if codes[ptr][0] == "jmp":
        codes[ptr][0]="nop"
        completed = process(codes,0,0,[],False)
        codes[ptr][0]="jmp"
    elif codes[ptr][0] == "nop":
        codes[ptr][0]="jmp"
        completed = process(codes,0,0,[],False)
        codes[ptr][0]="nop"
    if not completed :
        tryFix(codes,ptr+1)
def process (codes,ptr,acc,ran,isPart1):
    if ptr == len(codes):
        if not isPart1:
            print('part2:',acc)
        return True
    elif ptr in ran:
        if isPart1:
            print('part1:',acc)
        return False
    else:
        ran.append(ptr)
        acc,ptr = op[codes[ptr][0]](acc,ptr,codes[ptr][1])
        return process(codes,ptr,acc,ran,isPart1)
process(inlist,0,0,[],True)
tryFix(inlist,0)
