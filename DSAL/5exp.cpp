#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

struct node
{
    char data;
    node* left;
    node* right;
};

class Exptree
{
    public:
        node* root;
        node* create();    
        void postorder();
};

node* Exptree :: create()
{
    stack<node*> s1;
    char ex[10];
    node* nnode,*temp;
    cout<<"\nEnter Expression :- ";
    cin>>ex;

    int end=0;
    while(ex[end]!='\0')
    {
        end++;
    }
    
    for(int i=end-1;i>=0;i--)
    {
       node* nnode=new node;
       nnode->data=ex[i];
       nnode->left=nnode->right=NULL;

        if(ex[i]>='a' && ex[i]<='z')
        {
            s1.push(nnode);
        }
        else
        { 
          temp=s1.top();
          nnode->left=temp;
          s1.pop();
          temp=s1.top();
          nnode->right=temp;
          s1.pop();
          s1.push(nnode);
        }
    }
    return s1.top();
}

void Exptree:: postorder()
{ 
  node* root=create();
  node* temp;
  stack<node*> s3,s4;
  s3.push(root);

  while(!s3.empty())
 {   
    temp=s3.top();
    s3.pop();
    s4.push(temp);
      if(temp->left!=NULL)
       {
         s3.push(temp->left);
        }
      if(temp->right!=NULL)
       {
         s3.push(temp->right);
       }
  }
  
  cout<<"\nPostorder traversal: ";
   while(!s4.empty())
   { 
    temp=s4.top();
    cout<<" => "<<temp->data;
    s4.pop();
   }
}

int main()
{
    Exptree e;
    e.postorder();
    e.root=NULL;
    return(0);
}