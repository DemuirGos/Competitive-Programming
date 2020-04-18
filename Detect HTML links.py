import re
import sys
print("\n".join(",".join(j.strip() for j in i) for i in re.findall("\<a href=\"(.*?)\".*?\>(?<=\>)([\w\.\,\/ ]+)?(?=\<\/)",sys.stdin.read())))
