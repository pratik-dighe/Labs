#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class student
{
public:
	int roll;
	char name[100];
	long long int tele;
	char classn[50];
	char dob[10];

	static int count;
	student()
	{
		strcpy(name,"Pratik");
		roll=2133;
		tele=7822881173;
		strcpy(classn,"SE CE");
		strcpy(dob,"06/01/2003");
		count++;
	}

	student(student &p)
	{
		strcpy(name,p.name);
		roll=p.roll;
		tele=p.tele;
		strcpy(dob,p.dob);
		strcpy(classn,p.classn);
	}
	~student()
	{
		cout<<"\n"<<this->name<<" deleted";
	}

	void read()
	{
		cout<<"enter name";
		cin>>name;
		cout<<"enter roll";
		cin>>roll;
		cout<<"enter telephone";
		cin>>tele;
		cout<<"enter dob";
		cin>>dob;
		cout<<"enter classname";
		cin>>classn;
	}
	static void displaycount()
	{
		cout<<"\n number of students added"<<count;
	}
	friend void display(student s);
};
int student::count=0;
void display(student s)
{
	cout<<"\n DETAILS OF STUDENT";
	cout<<"\n class "<<s.classn;
	cout<<"\n name "<<s.name;
	//cout<<"\n class "<<s.classn;
	cout<<"\n telephone number "<<s.tele;
	cout<<"\n dob "<<s.dob;
}

int main()
{
	int d,i;
	student s1,*s[10];
	// <<"\n details os students";
	display(s1);
	cout<<"\ndetails of student in copy constructor ";
	student s2(s1);
	display(s2);

	cout<<"\nhow many students details you want to add";
	cin>>d;
	for(i=0;i<d;i++)
	{
		s[i]=new student();
		s[i]->read();
	}
	for(i=0;i<d;i++)
	{
		display(*s[i]);
		student::displaycount();
	}
	for(i=0;i<d;i++)
	{
		delete s[i];
	}
	getch();
	return(0);
}