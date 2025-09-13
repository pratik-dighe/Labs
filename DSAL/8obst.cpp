#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
class OBST
{
	string arr[10];
	float P[10],Q[10];
	float W[10][10],C[10][10];
	int r[10][10];
	int n;
	public:
		
		OBST()
		{
			for(int i=0;i<10;i++)
			{
				P[i]=Q[i]=0;
				for(int j=0;j<10;j++)
				{
					W[i][j]=C[i][j]=r[i][j]=1;
				}
			}
			
		}
		
		void get();
		void create();
		void display();
		void displayTree();
};

void OBST :: get()
{
	
	cout<<"\nEnter how many keys to insert :- ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter k"<<i+1<<" :- ";
		cin>>arr[i];
	}
	cout<<"\n*********Successful Probabilities**********"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"\nEnter Successful probabilities P"<<i<<" :- ";
		cin>>P[i];
	}
	cout<<"\n*********Unsuccessful Probabilities**********"<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<"\nEnter Unsuccessful probabilities Q"<<i<<" :- ";
		cin>>Q[i];
	}
	
}
	
void OBST :: create()
{
	for(int i=0;i<=n;i++)
	{
		C[i][i]=r[i][i]=0;
		W[i][i]=Q[i];
	}
	for(int i=0;i<=n-1;i++)
	{
		W[i][i+1]=P[i+1]+Q[i+1]+W[i][i];
		C[i][i+1]=W[i][i+1];
		r[i][i+1]=i+1;
	}
	for(int d=2;d<=n;d++)
	{
		for(int i=0;(d+i)<=n;i++)
		{
			int j=i+d;
			W[i][j]=P[j]+Q[j]+W[i][j-1];
			float minc=999;
			int root;
			for(int k=i+1;k<=j;k++)
			{
				float cost=C[i][k-1]+C[k][j];
				if(cost<minc)
				{
					minc=cost;
					root=k;
				}
			}
			C[i][j]=W[i][j]+minc;
			r[i][j]=root;
		}
	}
}
void OBST :: display()
{
	cout<<"\n*********OBST Matrix***********"<<endl;
	for(int i=0;i<=n;i++)
	{
		int k=0;
		for(int d=0;(d+i)<=n;d++)
		{
			int j=i+d;
			cout<<"\nW["<<k<<"]"<<"["<<j<<"] = "<<W[k][j]<<endl;
			cout<<"\nC["<<k<<"]"<<"["<<j<<"] = "<<C[k][j]<<endl;
			cout<<"\nr["<<k<<"]"<<"["<<j<<"] = "<<r[k][j]<<endl;
			
			k++;
		}
		cout<<endl;
		
	}
}

void OBST :: displayTree()
{
	queue<int> q;
	q.push(0);
	q.push(n);
	cout<<"Root\tLeft\tRight"<<endl;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		int j=q.front();
		q.pop();
		int k=r[i][j];
		cout<<k;
		if(r[i][k-1]==0)
		{
			cout<<"\tNULL ";
		}
		else
		{
			cout<<"\t"<<r[i][k-1];
			q.push(i);
			q.push(k-1);
		}
		if(r[k][j]==0)
		{
			cout<<"\tNULL ";
		}
		else
		{
			cout<<"\t"<<r[k][j];
			q.push(k);
			q.push(j);
		}
		cout<<endl;
			
	}

}
int main()
{
	OBST o;
	o.get();
	o.create();
	o.display();
	o.displayTree();
	return 0;	
}