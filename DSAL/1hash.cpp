
#include<iostream>
#include<cstring>
using namespace std;
#define size 10
struct record
{
    string name;
    long int tele;
};

class hashing
{
	public:
	 record hash[size];
	 hashing()
	 {
	 	
	    for(int i=0;i<size;i++)
			{
			hash[i].name="None";
			hash[i].tele=0;
			}
	 }
	 
	 void linearprobe();
	 void quadraticprobe();
	 void display();
	 friend void search(hashing h1,hashing h2);
	
		
 };

void hashing:: linearprobe()
{
	char nam[10],ch;
	long int tel;
	do
	{
	cout<<"\nEnter name and telephone number  :-";
        cin>>nam>>tel;
        int count=0;
        int add,add1,i=0;
        int flag=0;
        while(nam[i]!='\0')
        {
            count+=nam[i];
            i++;
        }
        
        add=count%size;
        if(hash[add].name=="None")
        {
        	hash[add].name=nam;
            hash[add].tele=tel;
            flag=1;
        }
        else
        {
        	for(int i=1;i<size;i++)
        	{
        		add1=(add+i)%size;
        		if(hash[add1].name=="None")
        		{
					hash[add1].name=nam;
					hash[add1].tele=tel;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\nNo Space Available";
			}
		}
		cout<<"\nDo you want to continue (y/n)  ";
		cin>>ch;
	}while(ch =='y');
}

void hashing:: quadraticprobe()
{
	char nam[10],ch;
	long int tel;
	do
	{
		cout<<"\nEnter name and telephone number  :-";
        cin>>nam>>tel;
        int count=0;
        int add,add1,i=0;
        int flag=0;
        while(nam[i]!='\0')
        {
            count+=nam[i];
            i++;
        }
        
        add=count%size;
        if(hash[add].name=="None")
        {
           hash[add].name=nam;
            hash[add].tele=tel;
            flag=1;
        }
        else
        {
        	for(int i=1;i<=(size-1)/2;i++)
        	{
        		add1=(add+(i*i))%size;
        		if(hash[add1].name=="None")
        		{
					hash[add1].name=nam;
					hash[add1].tele=tel;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\nNo Space Available";
			}
		}
		cout<<"\nDo you want to continue (y/n)  ";
		cin>>ch;
	}while(ch =='y');
}	

void hashing :: display()
{
	cout<<"\n***** Hash Table ****\n";
	cout<<"\nName\t\tTelephone";
	for(int i=0;i<size;i++)
	{
		cout<<"\n"<<hash[i].name<<"\t\t"<<hash[i].tele;
	}
}
void search(hashing h1,hashing h2)
{
		char nam[10];
 	    int chs;
 	    cout<<"\n1.Search in Linear probe\n2.Search in Quadratic probe ";
		cout<<"\nEnter your choice  ";
		cin>>chs;
        cout<<"\nEnter the record name which you want to find to find  :- ";
        cin>>nam;
        int count=0;
        int add,add1,i=0;
        int flag=0;
        while(nam[i]!='\0')
        {
            count+=nam[i];
            i++;
        }
        
        add=count%size;
		count=1;
	switch(chs)
		{
		   case 1:
			{
		      if(h1.hash[add].name==nam)
			    {
				   cout<<"\nTelephone number of "<<nam<<" is "<<h1.hash[add].tele<<"\n"; 
				
				  flag=1;
			    }
			 else
				{
				   for(int j=1;j<size;j++)
				    {
						add1=(add+j)%size;
						count++;
						if(h1.hash[add1].name==nam)
						{  
							cout<<"\nTelephone number of"<<nam<<"is"<<h1.hash[add1].tele<<"\n"; 
							flag=1;
							break;
					    }
				
				
		            }
		        }
		      cout<<"\nComparison take to search in linear probe :- "<<count;
			}
			break;

		    case 2:
			 {
				if(h2.hash[add].name==nam)
					{
						cout<<"\nTelephone number of "<<nam<<" is "<<h2.hash[add].tele<<"\n"; 
						flag=1;
					}
			    else
			      {
					for(int j=1;j<=(size-1)/2;j++)
						{
								add1=(add+(j*j))%size;
								count++;
								if(h2.hash[add1].name==nam)
									{  
									cout<<"\nTelephone number of "<<nam<<" is "<<h2.hash[add1].tele<<"\n"; 
									flag=1;
									break;
									}
								
								
						}
		          }
		     cout<<"\nComparison take to search above record in quadratic probe  is "<<count;
			 }
			break;

	    }

    if(flag==0)
    {
    	cout<<"\nRecord Is Not Found ";
    }
   
}

int main()
{
	int ch;
	hashing h1,h2;
	char chs;
	do
	{
	  
	   cout<<"\n1.Record for Linear Probe\n2.Record for Quadratic Probe\n3.Search the record \n4.Display linear probe\n5.Display quadratic probe ";
	   cout<<"\nEnter choice   ";
	   cin>>ch;
	   switch(ch)
		{
			case 1:
				h1.linearprobe();
				break;
			case 2:
				h2.quadraticprobe();
				break;
			case 3:
				search(h1,h2);
				break;
			case 4:
				h1.display();
				break;
			case 5:
				h2.display();
				break;
			default:
				cout<<"\nEnter valid choice ";
				break;
		}
		cout<<"\nDo you want to continue other dperation (y/n)  ";
		cin>>chs;
	}while(chs=='y');
    return(0);
}
