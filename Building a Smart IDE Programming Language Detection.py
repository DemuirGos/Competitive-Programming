import re
import sys
t=sys.stdin.read()
if re.search("(?i)(?m)import java\..*",t):
    print("Java")
elif re.search("(?i)(?m)\#include\<[a-zA-Z]+\.h\>",t):
    print("C")
else:
    print("Python")

