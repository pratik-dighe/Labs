#include<iostream>
#include<cstring>
using namespace std;

class publication
{
	public:
	char title[50];
	float price;
	
public:
	    publication()
	{
		strcpy(title," ");
	}
		void getdata()
		{
			cout<<"\nenter the title of book: ";
			cin>>title;
			cout<<"\nenter price of book: ";
			cin>>price;
		}
		void putdata()
		{
			cout<<"\ntitle of book: ";
			cout<<title;
			cout<<"\nprice of book: ";
			cout<<price;
		}
};
class book: public publication
{
	int pages;
public:
	void getdata_b()
	{
		cout<<"\nenter number of pages: ";
		cin>>pages;
	}
	void putdata_b()
	{
		cout<<"\nnumber of pages: ";
		cout<<pages;
	}
};
class Tape: public publication
{
	float tape;
public:
	void getdata_t()
	{
		cout<<"\nenter time: ";
		cin>>tape;
	}
	void putdata_t()
	{
		cout<<"\nplaytime: ";
		cout<<tape;
	}
};

int main()
{
	publication p;
	book b;
	Tape t;
	p.getdata();
	
	
	b.getdata_b();
	t.getdata_t();

	p.putdata();
	b.putdata_b();
	
	
	t.putdata_t();
    return(0);
}