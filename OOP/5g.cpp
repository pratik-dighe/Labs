#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
void selection(T a[10],int b)
{
	int i,j,temp;
	for(i=0;i<(b-1);i++)
	{
		for(j=i+1;j<b;j++)
		{

			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(i=0;i<b;i++)
	{
		cout<<a[i]<<" ";
	}


}
int main()
{
	int a[10],s1,s2,i;
	float b[10];
	cout<<"\nenter size of integer array";
	cin>>s1;
	for(i=0;i<s1;i++)
	{
		cin>>a[i];
	}
	cout<<"\nenter size of float array";
	cin>>s2;
	for(i=0;i<s2;i++)
	{
		cin>>b[i];
	}
	cout<<"\noriginal integer array: ";
	for(i=0;i<s1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\nsorted integer array: ";
	selection(a,s1);
	cout<<"\noriginal float array: ";
	for(i=0;i<s2;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<"\nsorted float array";
	selection(b,s2);
	getch();
	return(0);
}