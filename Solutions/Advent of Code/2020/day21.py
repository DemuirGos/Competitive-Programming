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
        return DeepMap({allergen:(allergens[allergen] if len(allergens[allergen])==1 else [element for element in allergens[allergen] if element not in heads]) for allergen in allergens})
    else:
        return allergens
part1 = len(filterFood(food,list(reduce(lambda x,y:x.union(y),[i for i in transformer({},dic).values()]))))
part2 = ",".join([list(i[1])[0] for i in sorted(DeepMap(transformer({},dic)).items(),key=lambda x:x[0])])
