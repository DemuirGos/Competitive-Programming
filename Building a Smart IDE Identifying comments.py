import re
import sys
print("\n".join(re.sub(r'\n\s+','\n',i[0]!="" and i[0] or i[1]) for i in re.findall(r'(?m)(?s)(\/\*.*?\*\/)|(\/\/.*?$)',sys.stdin.read())))
