n=input()
b=[0,0,0,0,0]
for i in n:
    if(i.isalnum()):
        b[0]+=1;
    if(i.isalpha()):
        b[1]+=1;
    if(i.isdigit()):
        b[2]+=1;
    if(i.islower()):
        b[3]+=1;
    if(i.isupper()):
        b[4]+=1;
for i in range(5):
    if(b[i]>0) :
        print("True")
    else :
        print("False")
