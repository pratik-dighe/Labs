#include<iostream>
#include<cstring>
using namespace std;
class stack
{
	public:
	int max = 100;
	char S[100] ;
	int top;
	public:
	stack()
	{
		top = -1;
	}
	
	
	int IsEmpty()
	{
		if(top == -1)
			return 1;
		else
			return 0;
	}
	
	
	int IsFull()
	{
		if(top == (max-1))
			return 1;
		else
			return 0;
	}
	
	
	void push(char ele)
	{
		
		if(!IsFull())
		{
			top++;
			S[top] = ele;
		}
		else
		{
			cout<<"\nThe stack is full";
		}
	}
	
	
	char pop()
	{
		if(!IsEmpty())
		{
			char e;
			e = S[top];
			top--;
			//cout<<"\n"<<e<<" is deleted";
			return(e);
		}
		else
		{
			return(-1);
		}
	}
	
	int getTop()
	{
		if(!IsEmpty())
		{
			cout<<"\nThe top element is "<<S[top];
			return(S[top]);
		}
	}
	
	void Palindrome()
	{
		int flag = 0;
		char pal[100];
		
		cout<<"\nEnter string: ";
		cin.getline(pal,100);
		int i = 0;
		while(pal[i]!='\0')
		{
			push(pal[i]);
			i++;
		}
		//cout<<s.S;
		i = top;
		cout<<"\nReversed string is: ";
		while(i > -1)
		{
			cout<<pal[i];
			i--;
		}
		//cout<<i;
		
		for(i=0;i<=top;i++)
		{
			if(pal[i]!=pop())
			{
				flag = 1;
				break;
			}
		}
		
		if(flag == 1)
		{
			cout<<"\nThe string isn't a palindrome";
		}
		else
		{
			cout<<"\nThe string is palindrome";
		}
	}		
	
};	

int main()
{
	stack s;
	s.Palindrome();
	return(0);
}
