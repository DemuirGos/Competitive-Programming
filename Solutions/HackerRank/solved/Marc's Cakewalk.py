n=int(input())
cal=[int(i) for i in input().split()]
cal.sort(reverse=True)
length = 0
for i in range(len(cal)):
    length+=2**i*cal[i]
print(length)
