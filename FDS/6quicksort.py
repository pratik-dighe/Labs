#EXPERIMENT NO:06

L=[]
r=int(input("first year student:"))
for i in range(r):
    roll=int(input("Enter percentage:"))
    L.append(roll)
   
                        
def partition(L,start,end):
    p=L[end]                    #p=pivot
    pi=start                    #pi=pindex
    
    for i in range(start,end):
        if(L[i]<=p):
            L[i],L[pi]=L[pi],L[i]
            pi=pi+1
    L[pi],L[end]=L[end],L[pi]
    print(L)
    return pi
   
def Quick_sort(L,start,end):
    if(start<end):
        pi=partition(L,start,end)
        Quick_sort(L,start,pi-1)
        Quick_sort(L,pi+1,end)
Quick_sort(L,0,r-1)
print("Quick sort:",L)
