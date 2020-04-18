def count_substring(s, ss):
    total=0
    for i in range(len(s)-len(ss)+1):
        for j in range(len(ss)):
            if(s[i+j]!=ss[j]):
                break
            if j== len(ss)-1:
                total+=1
    return total

