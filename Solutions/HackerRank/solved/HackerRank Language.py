import re
lang="(C:CPP:JAVA:PYTHON:PERL:PHP:RUBY:CSHARP:HASKELL:CLOJURE:BASH:SCALA:ERLANG:CLISP:LUA:BRAINFUCK:JAVASCRIPT:GO:D:OCAML:R:PASCAL:SBCL:DART:GROOVY:OBJECTIVEC)"
lang="|".join(lang.split(":"))
for _ in range(int(input())):
    s=input().split()
    n=int(s[0])
    m=s[1]
    if 10**4<n and n<10**5:
        if re.match("^"+lang+"$",m):
            print("VALID")
        else:
            print("INVALID")
    else:
        print("INVALID")
