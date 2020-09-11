for _ in range(int(input())):
    w=" "+input()
    r=0
    for i in range(1,len(w)):
        if w[i]==w[i-1]:
            r+=1
    print(r)
