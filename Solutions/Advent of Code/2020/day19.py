import re
strin=open("InputData\day19.txt", "r").read().split('\n\n')
def parse(rawRule):
    if re.match(r"^(\w+ )+|( \w+)+$",rawRule):
        return list(list(map(int,branch.split())) for branch in rawRule.split(' | '))
    else:
        return [[int(rawRule)]] if re.match("\d+",rawRule) else rawRule
rules={int(i[0]):parse(i[1]) for i in list(map(lambda line:line.strip().replace('"','').split(': '),strin[0].split('\n')))}
messages = strin[1].split('\n')
def check(rule,word,part):
    if part==2:
        rules.update({8: [[42],[42,8]],11:[[42,31],[42,11,31]]})
    if rule== [] or word=='':
        return rule== [] and word==''
    if isinstance(rules[rule[0]],list):
        return any(check(r + rule[1:],word) for r in rules[rule[0]])        
    elif isinstance(rules[rule[0]],str):
        return check(rule[1:],word[1:]) if word[0] == rules[rule[0]] else False
part1 = sum([check([0],m,part=1) for m in messages])
part2 = sum([check([0],m,part=2) for m in messages])
