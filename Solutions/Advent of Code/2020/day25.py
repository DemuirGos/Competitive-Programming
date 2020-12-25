doorKey,cardKey = (int(i) for i in open("InputData/day25.txt",'r').readlines())
Loop = lambda key,init,idx,val: idx if key == val else Loop(key,init,idx + 1, (val * init) % 20201227)
Loop2 = lambda init,idx,val: val if idx == 0 else Loop2(init,idx - 1, (val * init) % 20201227)
def loop1(key,init,idx,val):
    while key!=val:
        key,init,idx,val = key,init,idx + 1, (val * init) % 20201227
    return idx
def loop2(init,idx,val):
    while idx != 0:
        init,idx,val = init,idx - 1,(val * init) % 20201227
    return val
CardLoop = loop1(cardKey,7,0,1)
encryptionKey = loop2(doorKey,CardLoop,1)
part1 = encryptionKey