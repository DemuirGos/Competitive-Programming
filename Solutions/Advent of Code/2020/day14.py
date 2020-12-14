import re
strin=open("InputData\day14.txt", "r").read()
memos  = [[list(map(lambda x:int(x),*re.findall("mem\[(\d+)\] = (\d+)",m))) for m in p if m!=''] for p in [l.split('\n') for l in re.split("mask = [01X]+",strin) if l!='']]
masks1 = [(sum([int(v)*2**i if v=='0' else 1*2**i for i,v in enumerate(i[7:][::-1])]),sum([int(v)*2**i if v=='1' else 0*2**i for i,v in enumerate(i[7:][::-1])])) for i in strin.split('\n') if re.match("mask = [01X]+",i)]
def generateSubMasks(index,mask,i,r):
    def MaskProc(init,index,masked,v):
        if len(init)==0:
            return int(masked,2)
        else:
            if init[0]=='X':
                return MaskProc(init[1:],index[1:],masked + v[0],v[1:])
            else:
                return MaskProc(init[1:],index[1:],masked + index[0],v)
    if i < 0:
        return r
    else:
        return generateSubMasks(index.zfill(len(mask)),mask,i-1,r + [MaskProc(mask,index.zfill(len(mask)),'',format(i, '0' + str(mask.count('X'))+'b'))])
masks2 = [(l[7:].replace("X","0"),l[7:]) for l in strin.split('\n') if re.match("mask = [X01]+",l)]
maskedIndex=[(list(generateSubMasks(format(s[0]|int(masks2[i][0],2), '0' + str(len(masks2[i][1]))+'b'),masks2[i][1],(2**masks2[i][1].count('X'))-1,[])),s[1]) for i,v in enumerate(memos) for s in v]
part1  = sum([v for i,v in dict([l for idx,stmt in enumerate(memos) for l in [(i,v&masks1[idx][0]|masks1[idx][1]) for i,v in stmt]]).items()])
part2 = sum([i[1] for i in dict([(idx,o[1]) for o in maskedIndex for idx in o[0]]).items()])
