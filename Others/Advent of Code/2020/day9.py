strin=list(map(int,open("InputData\day9.txt", "r").read().split('\n')))
keysetsize = 25
part1 = sorted([(i,strin[i+keysetsize]) for i in range(len(strin[keysetsize:])) if len([(j,k) for j in strin[i:i+keysetsize] for k in strin[i:i+keysetsize] if k + j == strin[i+keysetsize]])==0])
memo=set()
def fracture(v,l,r,n):
    if (l,r) not in memo:
        memo.add((l,r))
        if sum(v[l:r])> n:
            fracture(v,l,r-1,n)
            fracture(v,l+1,r,n)
        elif sum(v[l:r])==n:
            print('part2:',sum([min(v[l:r]),max(v[l:r])])) 
fracture(strin,0,r[0][0]-1,r[0][1])
