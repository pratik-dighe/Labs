#include<iostream>
using namespace std;

struct node
{
	int data;
	node *right,*left;
};
node *root; 
node *nnode;
node *temp;

class binarytree
{
	public:
		binarytree()
		{
			root=NULL;
		}
		void create();
		void display(node *temp);
		void search();
		void min();
		void max();
		void mirror(node *temp);
};

void binarytree::create()
{
	char ch;
	do{
		nnode=new node;
		nnode->right=NULL;
		nnode->left=NULL;
		cout<<"\nEnter data";
		cin>>nnode->data;
		if(root==NULL)
		{
			root=nnode;
		}
		else
		{
			temp=root;
			while(1)
			{
				if((nnode->data)<(temp->data))
				{
					if(temp->left==NULL)
					{
						temp->left=nnode;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right=nnode;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
		cout<<"\nDo you want to add more nodes then press y";
		cin>>ch;
	}while(ch=='y');
}

void binarytree::display(node *temp)
{
	if(temp!=NULL)
	{
		display(temp->left);
		cout<<temp->data<<" ";
		display(temp->right);
	}
}

void binarytree::search()
{
	int key;
	cout<<"\nEnter key to search in tree";
	cin>>key;
	int flag=0;
	if(root==NULL)
	{
		root=nnode;
	}
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			if(key==temp->data)
			{
				cout<<"\nKey is present";
				flag=1;
				break;
			}
			else
			{
				if(key<temp->data)
				{
					temp=temp->left;
					break;
				}
				else
				{
					temp=temp->right;
				}
			}
		}
		if(flag==0)
		{
			cout<<"\nKey is Absent";
		}
	}
}

void binarytree::min()
{
	temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	cout<<"\nMinimum Value is";
	cout<<temp->data;
}

void binarytree::max()
{
	temp=root;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	cout<<"\nmaximum value is";
	cout<<temp->data;
}

void binarytree::mirror(node *temp)
{
	node* ne=new node;
	if(temp!=NULL)
	{
		mirror(temp->left);
		mirror(temp->right);
		ne=temp->left;
		temp->left=temp->right;
		temp->right=ne;
	}
}

int main()
{
	binarytree b;
	char ch;
	do
	{
		int n;
		cout<<"\n1.Creation\n2.Search\n3.Minimum data\n4.Mirror\n5.Display\n6.maximum\nEnter your choice";
		cin>>n;
		
		switch(n)
		{
			case 1:
			{
				b.create();
				break;
			}
			case 2:
			{
				b.search();
				break;
			}
			case 3:
			{
				b.min();
				break;
			}
			case 4:
			{
				b.mirror(root);
				break;
			}
			case 5:
			{
				b.display(root);
				break;
			}
			case 6:
			{
				b.max();
				break;
			}
		}
		cout<<"\nDo you want to continue further";
		cin>>ch;
	}while(ch=='y');
	return 0;
}