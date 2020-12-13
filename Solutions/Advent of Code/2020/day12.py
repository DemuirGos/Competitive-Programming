from math import sin,cos,radians 
import re
strin=re.findall("([A-Z])([0-9]+)",open("InputData\day12.txt", "r").read())
ops=[   lambda c,s,p:s if len(c) == 0 else ops[0](c[1:],ops[p][c[0][0]](s,int(c[0][1])),p),
        {
        'N':(lambda i,v:[(i[0][0] + v,i[0][1]),i[1]]),
        'S':(lambda i,v:[(i[0][0] - v,i[0][1]),i[1]]),
        'E':(lambda i,v:[(i[0][0],i[0][1] + v),i[1]]),
        'W':(lambda i,v:[(i[0][0],i[0][1] - v),i[1]]),
        'F':(lambda i,v:[(i[0][0] + v*sin(radians(i[1])),i[0][1] + v*cos(radians(i[1]))),i[1]]),
        'R':(lambda i,v:[(i[0][0],i[0][1]),(i[1] - v)%360]),
        'L':(lambda i,v:[(i[0][0],i[0][1]),(i[1] + v)%360]),
        },{
        'N':(lambda pw,v: [pw[0],pw[1],(pw[2][0] + v,pw[2][1])]),
        'S':(lambda pw,v: [pw[0],pw[1],(pw[2][0] - v,pw[2][1])]),
        'E':(lambda pw,v: [pw[0],pw[1],(pw[2][0] ,pw[2][1] + v)]),
        'W':(lambda pw,v: [pw[0],pw[1],(pw[2][0] ,pw[2][1] - v)]),
        'F':(lambda pw,v: pw if v==0 else ops[2]['F']([(pw[0][0] + pw[2][0],pw[0][1] + pw[2][1]),pw[1],pw[2]],v-1)),
        'R':(lambda pw,v: [pw[0],(pw[1]+v)%360,(lambda p,d:(-sin(d)*(p[1])+cos(d)*(p[0]),cos(d)*(p[1])+sin(d)*(p[0])))(pw[2],radians(v))]),
        'L':(lambda pw,v: [pw[0],(pw[1]-v)%360,(lambda p,d:(-sin(d)*(p[1])+cos(d)*(p[0]),cos(d)*(p[1])+sin(d)*(p[0])))(pw[2],-radians(v))]),
        }]
part1=int((lambda r:abs(r[0])+abs(r[1]))(ops[0](strin,[(0,0),0,(1,10)][:-1].copy(),1)[0]))
part2=int((lambda r:abs(r[0])+abs(r[1]))(ops[0](strin,[(0,0),0,(1,10)].copy(),2)[0]))
