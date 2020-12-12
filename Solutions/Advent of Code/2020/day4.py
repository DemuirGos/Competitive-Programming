import re
strin=open("InputData\day4.txt", "r").read().split('\n\n')
checks = {
            'byr':(lambda s:1920<=int(s)<=2002),
            'iyr':(lambda s:2010<=int(s)<=2020),
            'eyr':(lambda s:2020<=int(s)<=2030),
            'hgt':(lambda s:150<=int(s[:-2])<=193 if re.search("cm",s) else 59<=int(s[:-2])<=76 if re.search("in",s) else False),
            'hcl':(lambda s:re.match("#[0-9a-f]{6}",s)!=None),
            'ecl':(lambda s:s in "amb blu brn gry grn hzl oth".split()),
            'pid':(lambda s:True if re.match("[0-9]{9}",s) else False)
         }
part1=len([p for p in [dict(re.findall("(\w+):([#a-z0-9A-Z]+)",p)) for p in strin] if all(c in p for c in checks)])
part2=len([p for p in [dict(re.findall("(\w+):([#a-z0-9A-Z]+)",p)) for p in strin] if all(c in p and checks[c](p[c]) for c in checks)])
