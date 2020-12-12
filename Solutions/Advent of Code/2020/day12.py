from math import sin,cos,radians 
import re
state0=[(0,0),0,(1,10)]
strin=re.findall("([A-Z])([0-9]+)",open("InputData\day12.txt", "r").read())
op1 = {
        'N':(lambda i,v:[(i[0][0] + v,i[0][1]),i[1]]),
        'S':(lambda i,v:[(i[0][0] - v,i[0][1]),i[1]]),
        'E':(lambda i,v:[(i[0][0],i[0][1] + v),i[1]]),
        'W':(lambda i,v:[(i[0][0],i[0][1] - v),i[1]]),
        'F':(lambda i,v:[(i[0][0] + v*sin(radians(i[1])),i[0][1] + v*cos(radians(i[1]))),i[1]]),
        'R':(lambda i,v:[(i[0][0],i[0][1]),(i[1] - v)%360]),
        'L':(lambda i,v:[(i[0][0],i[0][1]),(i[1] + v)%360]),
     }
op2 = {
        'N':(lambda pw,v: [pw[0],pw[1],(pw[2][0] + v,pw[2][1])]),
        'S':(lambda pw,v: [pw[0],pw[1],(pw[2][0] - v,pw[2][1])]),
        'E':(lambda pw,v: [pw[0],pw[1],(pw[2][0] ,pw[2][1] + v)]),
        'W':(lambda pw,v: [pw[0],pw[1],(pw[2][0] ,pw[2][1] - v)]),
        'F':(lambda pw,v: pw if v==0 else op2['F']([(pw[0][0] + pw[2][0],pw[0][1] + pw[2][1]),pw[1],pw[2]],v-1)),
        'R':(lambda pw,v: [pw[0],(pw[1]+v)%360,(lambda p,d:(-sin(d)*(p[1])+cos(d)*(p[0]),cos(d)*(p[1])+sin(d)*(p[0])))(pw[2],radians(v))]),
        'L':(lambda pw,v: [pw[0],(pw[1]-v)%360,(lambda p,d:(-sin(d)*(p[1])+cos(d)*(p[0]),cos(d)*(p[1])+sin(d)*(p[0])))(pw[2],-radians(v))]),
     }
def process(codes,state,part):
    if len(codes)==0:
        return state
    else:
        if part==1:
            return process(codes[1:],op1[codes[0][0]](state,int(codes[0][1])),1)
        elif part==2:
            return process(codes[1:],op2[codes[0][0]](state,int(codes[0][1])),2)
part1=int((lambda r:abs(r[0]-state0[0][0])+abs(r[1]-state0[0][1]))(process(strin,state0[:-1].copy(),part=1)[0]))
part2=int((lambda r:abs(r[0]-state0[0][0])+abs(r[1]-state0[0][1]))(process(strin,state0.copy(),part=2)[0]))
