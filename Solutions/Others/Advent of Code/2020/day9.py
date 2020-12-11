strin=list(map(int,open("InputData\day9.txt", "r").read().split('\n')))
keysetsize = 25
part1 = sorted([(i,strin[i+keysetsize]) for i in range(len(strin[keysetsize:])) if len([(j,k) for j in strin[i:i+keysetsize] for k in strin[i:i+keysetsize] if k + j == strin[i+keysetsize]])==0])
part2 = (lambda x: min(x)+max(x))(*[strin[i:j] for i in range(len(strin[:part1[0][0]])) for j in range(len(strin[:part1[0][0]])) if sum(strin[i:j])==part1[0][1] and i!=part1[0][0]])
