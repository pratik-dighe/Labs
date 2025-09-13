#include<iostream>
using namespace std;
class parlor
{
  public:
    int f,r,max=5,n,pizza[15];
	parlor()
	 {
	   f=r=-1;
	 }
	int IsEmpty();
	int Isfull();
	void Enqueue();
	void display();
	void dequeue();
};

int parlor:: IsEmpty()
 {
   if (f==-1 && r==-1)
      return(1);
   else 
      return(0); 
 }

int parlor:: Isfull()
 {
   if ((r+1)%max==f)
      return(1);
   else 
      return(0);
}

void  parlor:: Enqueue()
 { 
   if(!Isfull())
    {
 	  cout<<"\nEnter your order: ";
 	  cin>>n;
 	  cout<<"pizza order "<<n<<" is succesfully reseived"; 
        if (f==-1)
         {
           f=0; 
         }
         r=(r+1)%max;
         pizza[r]=n;	 
    } 
   else
	{
	   cout<<"\nOrder is full ";
	}
}
void  parlor:: dequeue()
{
	if(IsEmpty())
	   { 
	     cout<<"\n All order are surve(empty) ";
	  }
	else
	  { 
	      if(f==r)
		   {
		        cout<<pizza[f]<<"order is surve\n ";  
		        f=r=-1;
		   }
	      else 
		   {
		        cout<<pizza[f]<<"order is surve\n ";  
		        f=(f+1)%max;
		   }   
	   }
	
	    
}
void  parlor:: display()
{
	if(!IsEmpty())
	 { 
	   /*int i;
	   i=f;
	   do{
	       cout<<pizza[i]<<" ";
	       i=(i+1)%max;
	       
	      }while(i!=f);*/
	      for (int i=f;i<=r;i++)
	   	{
	   	  cout<<pizza[i]<<"  ";
	   	}
	  }
	else
	 {
	 cout<<"\n pizza is not avilable " ;
	 }
}

int main()
 {
   parlor j;
   char ch;
   cout<<"\n please select this pizza order:";
   cout<<"\n 1.choclate";
   cout<<"\n 2.paneer";
   cout<<"\n 3.cheese";
   cout<<"\n 4.chiken";
   cout<<"\n 5.veg\n";
   do{
        int m ;
    	cout<<"\n1.pizza order\n2.surve order \n3.Display order\n";
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
	  cout<<"\nEnter y,if you continue further Pizza order(y/n): ";
	  cin>>ch;
	
    }while(ch=='y');

 return(0);

}
