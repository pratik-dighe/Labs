#include<iostream>
#include<string>
using namespace std;

struct node
{ 
	string k; //key
	string m; //meaning
	node *left; //left node
	node *right; //right node
	//int bf; //balance factor
};

class avltree
{
	public:
	node *root;
	avltree()
	{
	 root=NULL;
	}
		
	void insert();
	void display();
};

void avltree::insert()
{
	char ans;
	do{
	
		node *nnode=new node;
		cout<<"\nenter key: ";
		cin>>nnode->k;
		cout<<"\nenter meaning: ";
		cin>>nnode->m;
		cout<<"\ndo you want to add more node: ";
		cin>>ans;
	}while(ans=='y');
	
	
	node* temp;
	temp=root;
}

void avltree::display()
{
	node *nnode=new node;
	//cout<<"key: \n"<<nnode->k;
	//cout<<"meaning: \n"<<nnode->m;
	if(root!=NULL)
	{
		display(root->left);
		cout<<"\n Node is:"<<root->k<<"-"<<root->m;
		display(root->right);
	}
/*	
	void dict::display(dict* root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<"\n Node is:"<<root->word<<"-"<<root->mean;
		display(root->right);
	}
}*/

	/*if(root->cL!=NULL)
	display(root->cL);

	cout<<"\t"<<root->key;
	
	if(root->cR!=NULL)
	display(root->cR);*/
}

int main()
{
	node *root;
	root=NULL;
	avltree t1;
	int ch;
	do{
		cout<<"\nEnter your choice \n1.insert\n2.display\n3.exit\n";
		cin>>ch;

		switch(ch)
		{
			case 1:t1.insert();
			       break;
			case 2:t1.display();
			       break;
			       
			case 3:cout<<"exiting";
			       break;
		}
		
		
		
	}while(ch!=3);
	return 0;
}
