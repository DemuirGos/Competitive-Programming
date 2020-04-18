import sys
import re
print(";".join(sorted(list(set([i[3] for i in re.findall("http(s|):\/\/(ww(w|2)\.)?([\w\-\.]+\.[a-z]+)",sys.stdin.read()) ])))))
