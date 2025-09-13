#include<iostream>
using namespace std;

struct node
{
    char areaname[10];
    node *next;
};

node *head[10], *temp,*temp1,*nnode;

class area
{
    public:
    int n,max=3;
    int i,j;
    area()
    {
        for(i=0;i<max;i++)
        {
            head[i]=NULL;
        }
    }
    void create();
    void display();
};

void area::create()
{
    for(i=0;i<max;i++)
    {
        head[i]=new node;
        head[i]->next=NULL;
    }
    for(i=0;i<max;i++)
    {
        cout<<"\nenter area name";
        cin>>head[i]->areaname;
        cout<<"how many areas are connected to "<<head[i]->areaname;
        cin>>n;

        for(j=0;j<n;j++)
        {
            nnode=new node;
            nnode->next=NULL;
            cout<<"\nenter area name";
            cin>>nnode->areaname;
            temp=head[i];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nnode;
        }
    }
}

void area::display()
{
    temp=head[i];
    temp1=nnode;
    while(temp!=NULL)
    {
        cout<<head[i]->areaname;
        while(temp1!=NULL)
        {
            cout<<nnode->areaname;
            temp1=temp1->next;
        }
        temp=temp->next;
    }
}

int main()
{
    area a1;
    a1.create();
    a1.display();
    return 0;
}