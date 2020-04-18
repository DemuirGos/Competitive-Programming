if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    med=0
    j=0
    for i in student_marks[query_name]:
        med+=i
        j+=1
    med/=j
    print ('%.2f'%med)
    


