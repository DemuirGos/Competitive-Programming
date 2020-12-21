import re
from functools import reduce
ingredients =  open("InputData\day21.txt", "r").read().split('\n')
dic =sorted([(allergen,set(i.split(' (')[0].split())) for i in ingredients for allergen in re.findall("\(contains (.+)\)",i)[0].split(', ')])
food = [food for lst in ingredients for food in lst.split(' (')[0].split()]
def transformer(r,d):
    if len(d)==0:
        return r
    else:
        i,v = d[0]
        if i in r:
            r[i] = r[i].intersection(v)
            return transformer(r,d[1:])
        else :
            r[i] = v
            return transformer(r,d[1:])
def filterFood(f,a):
    if len(a)==0:
        return f
    else:
        return filterFood([food for food in f if food!=a[0]],a[1:])
def DeepMap(allergens):
    if any([len(c)!=1 for c in allergens.values()]):
        heads = [list(i)[0] for i in allergens.values() if len(i)==1]
        for head in heads:
            for allergen in allergens:
                if len(allergens[allergen])!=1 and head in allergens[allergen]:
                    allergens[allergen].remove(head)
        return DeepMap(allergens)
    else:
        return allergenMap
allergenMap = transformer({},dic)
part1 = len(filterFood(food,list(reduce(lambda x,y:x.union(y),[i for i in allergenMap.values()]))))
part2 = ",".join([list(i[1])[0] for i in sorted(DeepMap(allergenMap).items(),key=lambda x:x[0])])
