#include<iostream>
using namespace std;
class queue
{
  public:
    int f,r,max=5,n,job[15];
	queue()
	 {
	   f=r=-1;
	 }
	int IsEmpty();
	int Isfull();
	void Enqueue();
	void display();
	void dequeue();
};

int queue:: IsEmpty()
 {
   if (f==-1 && r==-1)
      return(1);
   else 
      return(0); 
 }

int queue:: Isfull()
 {
   if (r==max-1)
      return(1);
   else 
      return(0);
}

void  queue:: Enqueue()
 { 
   if(!Isfull())
    {
 	  cout<<"\nEnter a job: ";
 	  cin>>n;
 	  cout<<"Job no "<<n<<" is added succesfully"; 
        if (f==-1)
         {
           f++; 
         }
         r++;
         job[r]=n;	
         
    } 
   else
	{
	   cout<<"\nQueue is full,no more job is available ";
	}
}
void  queue:: dequeue()
{
	if(!IsEmpty())
	   { 
		  
	      if(f==r)
		   {
			cout<<job[f]<<" is deleted\n ";
		        f=r=-1;
		   }
	      else 
		   {
			cout<<job[f]<<" is deleted\n ";
		        f++;
		   }   
	   }
	else
	  {
	    cout<<"\n Queue is  empty ";
	  }
	  
}
void  queue:: display()
{
	if(!IsEmpty())
	 { 
	   for (int i=f;i<=r;i++)
	   	{
	   	  cout<<job[i]<<"  ";
	   	}
	 }
	else
	 {
	 cout<<"\nQueue is  empty " ;
	 }
}

int main()
 {
   queue j;
   char ch;
   do{
        int m ;
    	cout<<"\n1.Add a job\n2.Delete a job \n3.Display job\n";
		cout<<"Enter your choice:";
  		cin>>m;
		switch(m)
		 {
			case 1:
      	  	             {
	    	                j.Enqueue();
	   		        break;
	   		     }
	 		case 2:
	 		     {
	  			j.dequeue();
	   			break;
	 		     } 
	 		case 3:
	 		     {
	  			j.display();
	  			break;
	 		     }
	                default:cout<<"Invalid choice \n";
	                break;
	         }
	  cout<<"\nEnter y,if you continue further operation(y/n): ";
	  cin>>ch;
	
    }while(ch=='y');

 return(0);

}




