case = int(input())
n=int(input())
coin = sorted([int(i) for i in input().split()])
m=int(input())
jewelry = [int(i) for i in input().split()]

def test(jew , co):
    end = 0
    while co[end]<jew:
        end+=1
    if end == 0 :
        return "No Way"
    return "Too Many Way"
        

for c in range(case):
    for j in jewelry :
        print(test(j,coin))
