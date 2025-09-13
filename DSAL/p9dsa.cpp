#include <iostream>
#include <cstring>
using namespace std;
struct node
{
	string key;
	string meaning;
	int bal;
	node *left;
	node *right;
};
class AVL
{
public:
	node *root = NULL;
	node *temp = NULL;
	void insert();
	void display(node *temp);
	int height(node *temp2);
	void balance(node *temp3);
};
void AVL ::insert()
{
	char c;
	do
	{
		node *nnode = new node;
		nnode->bal = 0;
		nnode->left = nnode->right = NULL;
		cout << "\nEnter the key : ";
		cin >> nnode->key;
		// cout<<"\nEnter the meaning of key : ";
		// cin>>nnode->meaning;

		if (root == NULL)
		{
			root = nnode;
		}
		else
		{
			temp = root;
			while (1)
			{
				if (temp->key > nnode->key)
				{
					if (temp->left == NULL)
					{
						temp->left = nnode;
						break;
					}
					else
					{
						temp = temp->left;
					}
				}
				else
				{
					if (temp->right == NULL)
					{
						temp->right = nnode;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
			}
		}
		cout << "\nDo you want to continue (y/n): ";
		cin >> c;
	} while (c == 'y');
	balance(root);
	display(root);
	cout<<endl;
	cout <<"\n"<< height(root)<<endl;

}

int AVL ::height(node *temp2)
{
	int h1, h2;
	if (temp2 == NULL)
	{
		return (0);
	}
	if (temp2->right == NULL && temp2->left == NULL)
	{
		return 1;
	}
	h1 = height(temp2->left);
	h2 = height(temp2->right);
	if (h1 > h2)
	{
		return (h1 + 1);
	}
	else
	{
		return (h2 + 1);
	}
}

void AVL :: balance(node *temp3)
{
	if(temp3 != NULL)
	{
		balance(temp3->left);
		balance(temp3->right);
		int l = height(temp3->left);
		int r = height(temp3->right);
		temp3->bal = l - r;
	}
}

void AVL ::display(node *temp)
{
	if (temp != NULL)
	{
		display(temp->left);
		cout << temp->bal << "\t";
		display(temp->right);
	}
}

int main()
{
	AVL a;
	a.insert();
	cout << endl;
	return (0);
}
