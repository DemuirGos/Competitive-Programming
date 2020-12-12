strin=open("InputData\day5.txt", "r").read()
ops = {
            'F':(lambda h,w:[(h[0],(h[0]+h[1])//2),w]),
            'B':(lambda h,w:[((h[0]+h[1])//2,h[1]),w]),
            'L':(lambda h,w:[h,(w[0],(w[0]+w[1])//2)]),
            'R':(lambda h,w:[h,((w[0]+w[1])//2,w[1])])
        }
def main(d,code):
    if len(code)==0:
        return (d[0][1]*8+d[1][1],d)
    else:
        return main(ops[code[0]](d[0],d[1]),code[1:])
part0=[main([(0,127),(0,7)],i)[0] for i in strin.split('\n')]
part1=max(part0)
part2=[i for i in range(min(part0),max(part0)) if (i not in part0 and i+1 in part0 and i-1 in part0)]
