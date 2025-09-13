#EXPERIMENT NO:05

S=[]
s=int(input("first year student:"))
for i in range(s):
    perc=int(input("Enter percentage:"))
    S.append(perc)

#Bubble sort
for i in range(s):
    for j in range(s-1):
        if(S[j]>S[j+1]):
            S[j],S[j+1]=S[j+1],S[j]
print("1.Bubble sorted:",S)

#selection sort
for i in range(s-1):
    min=S[i]
    ind=i
    for j in range(i+1,s):
        if(S[j]<min):
            min=S[j]
            ind=j
     
    S[i],S[ind]=S[ind],S[i]
      
print("2.Selection sorted:",S)