strin=[[int(j) for j in i.split('\n')[1:]] for i in open("InputData/day22.txt",'r').read().split('\n\n')]
def LkbirYghlb(deck1,deck2):
    if any([len(i) == 0 for i in [deck1,deck2]]):
        return deck2 if len(deck1)==0 else deck1
    else:
        if deck1[0] > deck2[0]:
            return LkbirYghlb(deck1[1:]+ [deck1[0],deck2[0]],deck2[1:])
        else:
            return LkbirYghlb(deck1[1:],deck2[1:]+ [deck2[0],deck1[0]])
def playGame2(deck1,deck2,memo=[[]]*2):
    while all(len(i)!= 0 for i in [deck1,deck2]):
        if deck1 in memo[0] or deck2 in memo[1]:
            return (0,deck1)
        else:
            memo = [memo[0] + [deck1],memo[0] + [deck2]]
            winner = deck1[0] > deck2[0] if any([len(deck[1:]) < deck[0] for deck in [deck1,deck2]]) else playGame2(deck1[1 : 1 + deck1[0]], deck2[1 : 1 + deck2[0]])[0] == 0
            if winner:
                deck1,deck2 = deck1[1:] + [deck1[0], deck2[0]],deck2[1:]
            else:
                deck2,deck1 = deck2[1:] + [deck2[0], deck1[0]],deck1[1:]
    return (0,deck1) if len(deck1)!=0 else (1,deck2)
part1 = sum([v*(i+1) for i,v in enumerate(reversed(LkbirYghlb(*strin)))])
part2 = sum([v*(i+1) for i,v in enumerate(reversed(playGame2(*strin,[[]]*2)[1]))])
