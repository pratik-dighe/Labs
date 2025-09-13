#include<iostream>
using namespace std;

struct bnode
{
  int bit;
  bnode* next;
  bnode* previous;
};

bnode *nnode,*temp,*temp1,*temp2;
class binary
{
  public:
     bnode *head,*tail;
     binary()
     {
       head=tail=NULL;
     }
     void create();
     void compliment();
     void comple();
     void display();
     void add(binary,binary);
};

void binary::create()
{
int n;
cout<<"\n Enter a no:";
cin>>n;

while(n>0)
  {
    nnode=new bnode;
    nnode->next=nnode->previous=NULL;
    nnode->bit=n%2;
    if(head==NULL)
    {
      head=tail=nnode;
    }
    else
    {
      nnode->next=head;
      head->previous=nnode;
      head=nnode;
    }
    
    n=int(n/2);
  }
}  
void binary::compliment()
{
 cout<<"\n 1s compliment is:";
 temp=head;
 while(temp!=NULL)
 {
   if(temp->bit==1)
     cout<<"\t"<<0;
   else
     cout<<"\t"<<1;
     temp=temp->next;
 }
 cout<<"\n";
}

void binary::comple()
{
cout<<"\n 2s compliment is:";
int flag;
  temp=tail;
  flag=0;
  while(temp!=NULL)
  {
    if(flag==1)
    {
      if(temp->bit==1)
       {
        temp->bit=0;
       }
       else
       {
       temp->bit=1;
       }
      
    }
    else
     { 
       if(temp->bit==1)
        {
         temp->bit=1;
         flag=1;
        }
       else
        {
         temp->bit=0;
        }
     }
     
    temp=temp->previous;
   }
   display();
}

void binary::add(binary b1,binary b2)
{
  int carry;
  temp1=b1.tail;
  temp2=b2.tail;
  carry=0;
  while(temp1!=NULL && temp2!=NULL)
   {
     nnode=new bnode;
     nnode->next=nnode->previous=NULL;
     if(head==NULL)
     {
      head=tail=nnode;
     }
    else
    {
      nnode->next=head;
      head->previous=nnode;
      head=nnode;
    }
 
    if(temp1->bit==0 && temp2->bit==0 && carry==0)
    {
      nnode->bit=0;
      carry=0;
    }
    else if(temp1->bit==0 && temp2->bit==0 && carry==1)
    {
      nnode->bit=1;
      carry=0;
    }
    else if(temp1->bit==0 && temp2->bit==1 && carry==0)
    {
      nnode->bit=1;
      carry=0;
    }
    else if(temp1->bit==0 && temp2->bit==1 && carry==1)
    {
      nnode->bit=0;
      carry=1;
    }
    else if(temp1->bit==1 && temp2->bit==0 && carry==0)
    {
      nnode->bit=1;
      carry=0;
    }
    else if(temp1->bit==1 && temp2->bit==0 && carry==1)
    {
      nnode->bit=0;
      carry=1;
    }
    else if(temp1->bit==1 && temp2->bit==1 && carry==0)
    {
      nnode->bit=0;
      carry=1;
    }
    else if(temp1->bit==1 && temp2->bit==1 && carry==1)
    {
      nnode->bit=1;
      carry=1;
    }
   temp1=temp1->previous;
   temp2=temp2->previous;
  }
  while(temp1!=NULL)
  {
     nnode=new bnode;
     nnode->next=nnode->previous=NULL;
     if(head==NULL)
     {
      head=tail=nnode;
     }
    else
    {
      nnode->next=head;
      head->previous=nnode;
      head=nnode;
    }
    if(temp1->bit==0 && carry==0)
    {
      nnode->bit=0;
      carry=0;
    }
    else if(temp1->bit==0 && carry==1)
    {
      nnode->bit=1;
      carry=0;
    }
    else if(temp1->bit==1 && carry==0)
    {
      nnode->bit=1;
      carry=0;
    }
    else if(temp1->bit==1 && carry==1)
    {
      nnode->bit=0;
      carry=1;
    }
    temp1=temp1->previous;
   }
  while(temp2!=NULL)
  {
     nnode=new bnode;
     nnode->next=nnode->previous=NULL;
     if(head==NULL)
     {
      head=tail=nnode;
     }
    else
    {
      nnode->next=head;
      head->previous=nnode;
      head=nnode;
    }
   
    if(temp2->bit==0 && carry==0)
    {
      nnode->bit=0;
      carry=0;
    }
    else if(temp2->bit==0 && carry==1)
    {
      nnode->bit=1;
      carry=0;
    }
    else if(temp2->bit==1 && carry==0)
    {
      nnode->bit=1;
      carry=0;
    }
    else if(temp2->bit==1 && carry==1)
    {
      nnode->bit=0;
      carry=1;
    }
    temp2=temp2->previous;
   }
   
  if(carry==1)
  {
   nnode=new bnode;
   nnode->next=nnode->previous=NULL;
   
    nnode->next=head;
    head->previous=nnode;
    head=nnode;
    nnode->bit=1;
    
  }
  
} 
    
    
void binary::display()
{
  
     temp=head;
     while(temp!=NULL)
        {
	    cout<<"\t" <<temp->bit<<" ";
	    temp=temp->next;
        }
        cout<<"\n";   
}

int main()
{
 binary b1,b2,b,a,b3;
cout<<"\nBinary number:-";
 b1.create();
 b1.display();
 b1.compliment();
 b1.comple();
 cout<<"\n First binary no:";
 b.create();
 b.display();
 cout<<"\n second binary no:";
 a.create();
 a.display();
 b3.add(b,a);
 cout<<"\n Addition of binary no:";
 b3.display();
 return(0);
}