import re
import operator as OP
generalRules = {"*":(2,OP.mul),"/":(2,OP.add),"+":(1,OP.add),"-":(1,OP.add)}
expr = lambda s : list(map(lambda x : int(x) if re.match("\d+", x) else x, re.sub('\(',' ( ', re.sub('\)',' ) ',s)).split()))
strin = list(map(expr,open("InputData\day18.txt", "r").read().split('\n')))
def process(ixpr,op):
    def convert(ixpr, expr, acc, op):
        if len(ixpr) == 0:
            return expr + list(acc)[::-1]
        else:
            if isinstance(ixpr[0], int) :
                return convert(ixpr[1:], expr + [ixpr[0]], acc, op)
            else:
                def dropWhile(stack, pred, acc):
                    if pred(stack):
                        return dropWhile(stack[:-1] ,pred, acc + [stack[-1]])
                    else:
                        return (stack,acc)
                if ixpr[0]!=')' and ixpr[0]!='(':
                    if len(acc)==0 or acc[-1]=='(' or op[acc[-1]][0] < op[ixpr[0]][0]:
                        return convert(ixpr[1:],expr,acc+list(ixpr[0]), op)
                    else:
                        acc,fix = dropWhile(acc,lambda s: len(s)!=0 and op.get(ixpr[0],[-1])[0] <= op.get(s[-1],[-1])[0],[])
                        return convert(ixpr[1:],expr + fix if fix != [] else expr ,acc+[ixpr[0]], op)
                elif ixpr[0]=='(':
                    return convert(ixpr[1:],expr,acc+[ixpr[0]], op)
                else:
                    acc,fix = dropWhile(acc,lambda s: s[-1]!='(',[])
                    return convert(ixpr[1:],expr + fix if fix != [] else expr ,acc[:-1], op)
    def evaluate(expr,stack,op):
        if len(expr) == 0:
            return stack[0]
        else:
            if isinstance(expr[0], int):
                return evaluate(expr[1:],stack+[expr[0]],op)
            else:
                return evaluate(expr[1:],stack[:-2] + [op[expr[0][0]][1](stack[-1],stack[-2])],op)
    return evaluate(convert(ixpr,[],[], op),[],op)
part1 = sum(list(map(lambda e:process(e,{"*":(0,OP.mul),"+":(0,OP.add)}),strin)))
part2 = sum(list(map(lambda e:process(e,{"*":(0,OP.mul),"+":(1,OP.add)}),strin)))
