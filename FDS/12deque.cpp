#include<iostream>
using namespace std;
class doubleended
{
  public:
    int f,r,max=15,ele,Q[15],i=0;
	doubleended()
	 {
	   f=r=-1;
	 }
	int IsEmpty();
	int Isfull();
	void insert_front();
	void delete_front();
	void insert_rear();
  void delete_rear();
  void display();
};

int doubleended:: IsEmpty()
 {
   if (f==-1 && r==-1)
      return(1);
   else 
      return(0); 
 }

int doubleended:: Isfull()
 {
   if (r==max-1 && f == 0)
      return(1);
   else 
      return(0);
}

void doubleended::insert_front()
{
  if(!Isfull())
  {
    cout<<"\nEnter the element: ";
    cin>>ele;
    if(f == 0)
      cout<<"\nTry inserting from rear";
    else if(f == -1)
    {  
      f++;
      r++;
      Q[f]=ele;
    }
    else
    {
      f--;
      Q[f]=ele;
    }    
  }
  else
  {
    cout<<"\nQueue overflow";
  }

}

void doubleended::delete_front()
{
  if(IsEmpty())
  {
    cout<<"\nThe queue is empty";
  }
  else
  {
    cout<<"\n"<<Q[f]<<" is deleted";
    if(f==r)
      f=r=-1;
    else
      f++;
  }
}

void doubleended::insert_rear()
{
  if(Isfull())
    cout<<"\nQueue overflow";
  else
  {
    cout<<"\nEnter the element: ";
    cin>>ele;
    if(f==-1)
      f++;
    
    else if(r == max-1)
      cout<<"\nTry inserting from front";
    r++;
    Q[r]=ele;
  }
}

void doubleended::delete_rear()
{
  if(IsEmpty())
    cout<<"\nThe Queue is empty";
  else
  {
    cout<<"\n"<<Q[r]<<" is deleted";
    if(f==r)
      f=r=-1;
    else
      r--;
  }
}

void doubleended::display()
{
  if(IsEmpty())
  {
    cout<<"\nThe queue is empty";
  }
  else
  {
    for(i=f;i<=r;i++)
    cout<<Q[i]<<" ";
  }
}

int main()
{
  doubleended d;
  int ch;
  char c;
  do
  {
    cout<<"\n1.Insert Front \n2.Insert Rear \n3.Delete Front \n4.Delete Rear \n5.Display Queue"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1:
              d.insert_front();
              d.display();
              break;
      case 2:
              d.insert_rear();
              d.display();
              break;
      case 3:
              d.delete_front();
              d.display();
              break;
      case 4:
              d.delete_rear();
              d.display();
              break;
      case 5:
              d.display();
              break;
      default:cout<<"\n Invalid choice";
              break;
    }
    cout<<"\n Do you want to perform more operation?(y/n): ";
    cin>>c;
 } while (c=='y' || c=='Y');
return(0);
  
}