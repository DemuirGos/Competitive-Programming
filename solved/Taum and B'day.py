#!/bin/python3

import math
import os
import random
import re
import sys

def taumBDAY(b,w,bc,wc,z):
    x=int(b)*int(bc)+int(w)*int(wc)
    y=int(b)*int(wc)+int(b)*int(z)+int(wc)*int(w)
    a=int(w)*int(bc)+int(w)*int(z)+int(bc)*int(b)
    op = [a,x,y]
    min=op[2]
    for i in range(3):
         if op[i] <= min : 
             min=op[i]
    return min
n=int(input())
for i in range(n):
    b,w=input().split()
    bc,wc,z=input().split()
    print(taumBDAY(b,w,bc,wc,z))

