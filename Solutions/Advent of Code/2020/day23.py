cup = [int(i) for i in list("247819356")] #+ list(range(10,1000001))
def move(cups,idx):
    if idx==0:
        idx = cups.index(1)
        return "".join(str(i) for i in cups[idx+1:]+cups[:idx])
        #return cups[idx+1:idx+3]
    else:
        curr = cups[0]
        neighbors = cups[1:4]
        possible = cups[4:]
        tail = cups[1:]
        dest = curr - 1 or max(tail)
        while dest in neighbors:
            dest = dest - 1 or max(tail)
        dest = cups.index(dest)
        result = tail[3:dest] + neighbors + tail[dest:] + [cups[0]]
        return move(result,idx-1)
part1 = move(cup,100)
print(cup[0:20])
#print(move(cup,10000000))
