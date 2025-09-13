#include<iostream> 
using namespace std;
struct node
  {
    int prn;
    char name[10]; 
    node *next;
  };
node *nnode, *temp,*temp1,*temp2; 
class pinacle
  {
    public:
        node *head,*tail;
        pinacle()
        {
            head=tail=NULL;
        } 
    void create();
    void insert();
    void deleation();
    void display();
    void count();
    void concatenation(pinacle);
 };

void pinacle::create()
{
char choice;
do{
    nnode=new node;
    nnode->next=NULL;
    cout<<"\n Enter the PRN:"; 
    cin>>nnode->prn;
    cout<<"\n Enter the name: ";
    cin>>nnode->name;

    if(head==NULL)
      {
        head=tail=nnode;
      }
    else
      {
        tail->next=nnode;
        tail=nnode;
      }
     cout<<"\n Do you want add more nnode:";
    cin>>choice; 
   }while(choice=='y');
  
}

void pinacle::insert()
{
 char choice;
  do{
    
    int ch;
    cout<<"\n 1.President\n 2.Secreatory\n 3.To add member between the linklist";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    nnode=new node;
    nnode->next=NULL;
    cout<<"\n Enter the PRN:"; 
    cin>>nnode->prn;
    cout<<"\n Enter the name: ";
    cin>>nnode->name;
    switch(ch)
      {
         case 1: 
                 if(head==NULL)
                 {
                    head=tail=nnode;
                 } 
                else
                 {
                  nnode->next=head;
                  head=nnode;
                 }
                break;
         case 2:if(head==NULL)
                 {
                   head=tail=nnode;
                 }
                else
                 {
                   tail->next=nnode;
                   tail=nnode;
                 }
            break;
        case 3:
                int m;
                cout<<"\n Enter prn number of member where after insertion has to take place \n"; 
                cin>>m;
                temp1=head; 
                while(temp1->prn!=m)
                 {
                   temp1=temp1->next;
                 }
                temp2=temp1->next;
               
                temp1->next=nnode;
                 nnode->next=temp2;
                break;
       
       default:cout<<"\nInvalid choice";
                break;
      }         
      cout<<"\n Do you want add more nnode:";
    cin>>choice; 
   }while(choice=='y');
}        
void pinacle::deleation()
{
  int n;
  cout<<"\nEnter the prn no we want to delete:";
  cin>>n;
  temp=head;
  while(temp->prn!=n)
    {
      temp=temp->next;
    }
  if(temp==head)
    {
      head=temp->next;
      delete temp;
    }
   else if(temp==tail)
   {
     temp1=head;
     while(temp1->next->prn!=n)
     {
       temp1=temp1->next;
     }
     tail=temp1;
     delete temp;
     temp1->next=NULL;
   }
  else
  {
   temp2=temp->next;
   temp1=head;
   while(temp1->next!=temp)
   { 
     temp1=temp1->next;
   }
   temp1->next=temp2;
   delete temp;
  }
   

}
void pinacle::count()
{
  int c=0;
  temp=head;
  while(temp!=NULL)
  {
    c++;
    temp=temp->next;
  }
  
  cout<<"\nTotal number member of:"<<c<<"\n";
 }

void pinacle::concatenation(pinacle p2)
{
  tail->next=p2.head;
}

void pinacle::display()
  {cout<<"\nDisplay link list:-";
     temp=head;
     while(temp!=NULL)
        {
	    cout<<"\n" <<temp->prn <<" "<<temp->name;
	    temp=temp->next;
        }
        cout<<"\n"; 
   }
int main()
{
  pinacle p,p2;
  char o;
  do{
    int r;
    cout<<"\n 1.Create a list\n 2.Insert a node\n 3.Delete a node\n 4.Display a list\n 5.count link list node\n 6.To concatenation a linklist";
    cout<<"\nEnter your choice: ";
    cin>>r;
    switch(r)
      { 
        case 1:
              p.create();
              p.display();
              break;
        case 2:
              p.insert();
              p.display();
              break;
        case 3:
              p.deleation();
              p.display();
              break;
        case 4:
              p.display();
              break;
        case 5:
              p.count();
              break;
        case 6:cout<<"\n to perform concatenation create 2nd div club";
               p2.create();
               cout<<"\n members of second div club are ";
               p2.display();
               p.concatenation(p2);
               cout<<"\n modified club members are ";
               p.display();
               
               break;
      }
     cout<<"Enter y,If you want to continue furthr operation=";
     cin>>o;
   }while(o=='y');
   return(0);
}
 
