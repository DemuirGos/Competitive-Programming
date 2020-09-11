def merge_the_tools(string, k):
    s=[ string[i:i+k] for i in range(0, len(string), k) ]
    for i in s:
        d={}
        for j in i:
            if(j not in d):
                print(j,end='')
                d[j]=1
        print()
