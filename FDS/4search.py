#EXPERIMENT NO:04

L=[]
r=int(input("Student attended program:"))
for i in range(r):
    roll=int(input("Enter a roll no:"))
    L.append(roll)
print(L)

#linear search
p=int(input("1)Enter a roll no:"))
for i in range(r):
    flag=0;
    if(p==L[i]):
        flag=1;
        break
if( flag==1):          #(i<r)
    print(" -Student is present")
else:
    print(" -Student absent")
      
#sentinel search  
c=int(input("2)Enter a roll no:"))

L.append(c)
i=0
for i in range(r+1):  #while(L[i]!=c)
    if(L[i]==c):      #i=i+1 
        break
    i=i+1
if(i<r):              #(i==r student is absent)
    print(" -Student is present")
else:
    print(" -Student absent")             
        
    
#Binary search
d=int(input("3)Enter a roll no:"))
low=0
high=r-1
while(low<=high):
    mid=(low+high)//2
    flag=0
    
    if(L[mid]>d):
        high=mid-1
    elif(L[mid]<d):
        low=mid+1
    elif(L[mid]==d):
        flag=1
        break
if(flag==1):
    print(" -Student is present")
else:
    print(" -Student absent")


#fibonacci search
a=int(input("4)Enter a no:"))
fib=1
fib1=1
fib2=0
while(fib<r):
    fib2=fib1
    fib1=fib
    fib=fib1+fib2

flag=0
i=0
offset=-1
while(fib>1):
    i=min(offset+fib2,r-1)
      
    if(a==L[i]):
       flag=1
       break
    elif(a>L[i]):
        fib=fib1
        fib1=fib2 
        fib2=fib-fib1
        offset=i
        
    elif(a<L[i]):
        fib=fib2
        fib1=fib1-fib2
        fib2=fib-fib1
        
if(flag==1):
    print(" -student is present") 
    
else:
    print(" -Student absent")      
        
    
    
    