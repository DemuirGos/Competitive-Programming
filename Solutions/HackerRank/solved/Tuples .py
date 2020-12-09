n = int(input())
i_l = input().split()
for _ in range(len(i_l)):
    i_l[_]=int(i_l[_])
i_l=tuple(i_l)
print(hash(i_l))

