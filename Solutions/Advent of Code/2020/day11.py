import sys
state0=list(map(lambda line:list(map(lambda c:1 if c=='L' else -1 if c=='#' else 0,line)),open("InputData\day11.txt", "r").read().split('\n')))
def offsets(state,p,isPart1):
    offsets=[(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1),(-1,0)]
    if isPart1:
        return offsets
    else:
        def spread(state,offs,i,p,r):
            if len(offs)==0:
                return r
            elif 0 <= p[0] + offs[0][0] < len(state[0]) and 0 <= p[1] + offs[0][1] < len(state) and state[p[1]+offs[0][1]][p[0]+offs[0][0]]==0:
                return spread(state, [tuple([a+b for (a,b) in zip(offs[0],offsets[i])])] + offs[1:],i,p,r)
            else:
                return spread(state,offs[1:],i + 1,p,r+[offs[0]])
        return spread(state,offsets,0,p,[])
            
def countadj(state,i,j,offs,r):
    if len(offs)!=0:
        if 0 <= i + offs[0][0] < len(state[0]) and 0 <= j + offs[0][1] < len(state):
            return countadj(state,i,j,offs[1:],((j,i),r[1] + (1 if state[j + offs[0][1]][i + offs[0][0]] == -1 else 0)))
        else:
            return countadj(state,i,j,offs[1:],r)
    else:
        return r
def NextState(old,state,isPart1):
    sideEffect = (lambda s,r:1 if s[r[0][0]][r[0][1]] == -1 and r[1]>=5 else -1 if s[r[0][0]][r[0][1]] == 1 and r[1]==0 else s[r[0][0]][r[0][1]])
    return [state.copy(),[[sideEffect(state,countadj(old,s,l,offsets(state,(s,l),isPart1),((l,s),0)))  for s in range(len(state[0]))] for l in range(len(state))]]
def engine(states,isPart1):
    if states[0]!=states[1]:
        return engine(NextState(states[1].copy(),states[1],isPart1),isPart1)
    else:
        return states[0]
print(sum([sum([1 for s in l if s==-1]) for l in engine(NextState(state0.copy(),state0,False),False)]))
