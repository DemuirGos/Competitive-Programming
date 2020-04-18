for _ in range(int(input())):
    s=input().split()
    n=int(s[0])
    k=int(s[1])
    l=0
    for i in range(1,n+1):
        if(k!=0 and (n%k!=0 or (n/k)%2!=0)):
            print(-1,end='')
            break
        print(i+((-1)**l)*k,end=' ')
        if(k!=0 and i%k==0):
            l+=1
    print()
