#EXPERIMENT NO:02

U=[]
u=int(input("student in class:"))
for i in range(u):
    roll=input("Enter the roLl no:")
    U.append(roll)
print(U)

P=[]
p=int(input("student present on exam day:"))
for i in range(p):
    roll=input("Enter the roLl no:")
    P.append(roll) 

#Average score of class
A=[]
sum=0
for i in range(p):
    marks=int(input("Marks of student:"))
    A.append(marks)

    sum=sum+marks
avg=sum/p
print(A)
print("1.Average score of class:",avg)

    
#Heighest score and lowest score of class

high=A[0]
for i in range(p):
    if(high<A[i]):
        high=A[i]
print("2.i)Heighest score is:",high)
    

low=A[0]
for i in range(p):
    if(low>A[i]):
        low=A[i]
print(" ii)Lowest score is:",low)

#Student is absent on exam
N=[]
for i in range(u):
    flag=0
    for j in range(p):
        if(P[j]==U[i]):
            flag=1
            break
    if(flag==0):
        N.append(U[i])
print("3.Student is absent on exam:",N)

#Marks with higher frequency
F=[]
for i in range(p):
    h=0
    for j in range(p):
        if(A[j]==A[i]):
            
            h=h+1
        
    F.append(h)

ind=0
high=0
v=0
for j in range(p):
    if(F[j]>high):
        high=F[j]
        ind=A[j]
        
for i in range(p):
    if(F[j]==F[i]):
        if(A[j]!=A[i]):
            v=A[j]
print("4.High frequency is",high,"and no is",ind,v)