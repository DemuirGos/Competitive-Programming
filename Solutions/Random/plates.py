# order in ascending order plates by size or impossible of no ordering is found
# where in put is as a set of comparaisons between the plates IDs
# each plate has a char [A-Z] as ID
# input : # possible case example :
# 	A<B
#	B<E
#	C>E
# output:
#	A,B,E,C
# input : # possible case example :
# 	A<B
#	B<C
#	C<A
# output:
#	impossible

import sys
instr = list(map(list,sys.stdin.readlines()))
graph={}
for e in instr:
    source,destin = e[0] if e[1]=='<' else e[2],e[2] if e[1]=='<' else e[0]
    if source in graph:
        graph[source]+=[destin]
    else:
        graph[source]=[destin]
print(graph)
pot=[s for s in graph for d in graph if s not in graph[d]]
if len(pot)==0:
    print("impossible")
else:
    def traverse(g,n,r,v):
        for d in graph[n]:
            if d in v :
                return "impossible"
            if d in graph :
                return traverse(g,d,r+[d],v+[d])
            else:
                return ("".join(r+[d]))
    for s in pot:
        r = traverse(graph,s,[s],[s])
        print(r)
        break
