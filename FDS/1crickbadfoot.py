#1 cricket badminton football

U=[]
u=int(input("enter total num of students: "))
for i in range(u):
    roll=input("enter roLl no: ")
    U.append(roll)

A=[]
a=int(input("how many student play cricket: "))
for i in range(a):
    roll=input("enter roll no: ")
    A.append(roll)
    
B=[]
b=int(input("how many student play badminton:"))
for i in range(b):
    roll=input("enter roLl no:")
    B.append(roll)
    
C=[]
c=int(input("how many student play football:"))
for k in range(c):
    roll=input("enter roLl no:")
    C.append(roll)

#Students play both cricket and badminton
M=[]
def intersect():
    for i in range(a):
        for j in range(b):
            if(B[j]==A[i]):
                M.append(A[i])
intersect()
print("1) Student play both cricket and badminton:", M)

#student play either cricket or badminton but not both
N=[]
for i in range(a):
    N.append(A[i])
for j in range(b):
    flag=0;
    for k in range(a):
        if(A[k]==B[j]):
            flag=1;
            break
    if(flag==0):
        N.append(B[j])

x=len(M)
y=len(N)
O=[]
for i in range(y):
    flag=0;
    for j in range(x):
        if(M[j]==N[i]):
            flag=1;
            break
    if(flag==0):
        O.append(N[i])
print("2) Student play either cricket or badminton but not both:",O)

#No. of student who play neither cricket nor badminton
P=[]
for i in range(u):
    flag=0;
    for j in range(y):
        if(N[j]==U[i]):
            flag=1;
            break
    if(flag==0):
        P.append(U[i])
print("3) Student play neither cricket nor badminton:",P)

#No. of student who play cricket and football but not badminton
R=[]
def intersect():
    for i in range(a):
        for j in range(c):
            if(C[j]==A[i]):
                R.append(A[i])
intersect()

z=len(R)
Q=[]
for i in range(z):
    flag=0;
    for j in range(b):
        if(B[j]==R[i]):
            flag=1;
            break
    if(flag==0):
        Q.append(R[i])
print("4) Student play cricket and football but not badminton:",Q)