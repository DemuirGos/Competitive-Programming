strin=list(enumerate(map(int,open("InputData\day1.txt", "r").split(','))))
def process(l,starters):
    r,dictionary=strin[len(strin)-1][1],{n:(i) for i,n in strin}
    for i in range(len(starters)-1,l-1):
        dictionary[r],r =i, i - dictionary.get(r,i)
    return r
part1 = process(2020,strin)
part2 = process(30000000,strin)
