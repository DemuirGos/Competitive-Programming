strin=list(enumerate(map(int,open("InputData\day15.txt", "r").read().split(','))))
def process(l,starters):
    r,dictionary=starters[-1][1],{n:(i) for i,n in starters}
    for i in range(len(starters)-1,l-1):
        dictionary[r],r =i, i - dictionary.get(r,i)
    return r
part1 = process(2020,strin)
part2 = process(30000000,strin)
