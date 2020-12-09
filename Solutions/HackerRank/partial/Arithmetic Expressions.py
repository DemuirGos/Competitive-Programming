
m = int(input())
numbers = [int(i) for i in input().split()]
op=['*',"-","+"]
def function(result,k,n):
    if(k==len(numbers)):
        if(n%101==0):
            print(result)
        return
    else:
        for i in range(len(op)):
            if i== 0:
                function(result + op[i] + str(numbers[k]),k +1,n*numbers[k])
            elif i == 1:
                function(result + op[i] + str(numbers[k]),k +1,n-numbers[k])
            elif i== 2:
                function(result + op[i] +  str(numbers[k]),k +1,n+numbers[k])
function(str(numbers[0]),1,numbers[0])
