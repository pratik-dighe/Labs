#EXPERIMENT NO:03

r=int(input("Enter the row:"))
c=int(input("Enter the column:"))

M1=[]
for i in range(r):
    sublist=[]
    for j in range(c):
        b=int(input("Enter a element:"))
        sublist.append(b)
    M1.append(sublist)
    
print("First matrix:",M1)

M2=[]
for i in range(r):
    sublist=[]
    for j in range(c):
        b=int(input("Enter a element:"))
        sublist.append(b)
    M2.append(sublist)
    
print("Second matrix:",M2)

#Addition of matrix
Add=[]
for i in range(r):
    sublist=[]
    for j in range(c):
        s=M1[i][j]+M2[i][j]
        sublist.append(s)
    Add.append(sublist)
    
print("1.Addition of matrix:",Add)

#substraction of matrix
sub=[]
for i in range(r):
    sublist=[]
    for j in range(c):
        s=M1[i][j]-M2[i][j]
        sublist.append(s)
    sub.append(sublist)
    
print("2.substraction of matrix:",sub)

#Multiplication of matrix
mul=[]
for i in range(c):
    sublist=[]
    for j in range(r):
        sum=0
        for k in range(r):
            b=M1[i][k]*M2[k][j]
            sum=sum+b
        sublist.append(sum)
    mul.append(sublist)
            
print("3.Multiplication of matrix:",mul) 

#Transpose of matrix  
trans=[]
for i in range(r):
    sublist=[]
    for j in range(c):
        d=M1[j][i]
        sublist.append(d)
    trans.append(sublist)
    
print("4.i)Transpose of first matrix:",trans)  

trans=[]
for i in range(r):
    sublist=[]
    for j in range(c):
        d=M2[j][i]
        sublist.append(d)
    trans.append(sublist)
    
print("  ii)Transpose of second matrix:",trans)  

