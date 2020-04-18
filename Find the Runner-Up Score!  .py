n = int(input())
arr = list(map(int, input().split()))
arr.sort()
m=max(arr)
for i in range(len(arr)):
    if arr[i+1]==m:
        print(arr[i])
        break
