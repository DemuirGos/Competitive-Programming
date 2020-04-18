

# Complete the solve function below.
def solve(s):
    result=""
    for i in range(0,len(s)):
        if(i==0):
            result+=s[i].capitalize()
            continue
        if(s[i-1]==' '):
            result+=s[i].capitalize()
            continue;
        result+=s[i]
    return result

