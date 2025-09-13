#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class student
{
	char name[100];
	int roll;
public:
	/*student()
	{
		strcpy(name," ");
	}*/
	void getdata()
	{
		cout<<"enter name";
		cin>>name;
		cout<<"enter roll";
		cin>>roll;
	}
	void putdata()
	{
		cout<<"\nname: ";
		cout<<name;
		cout<<"\troll ";
		cout<<roll;
	}
};
int main()
{
	int i,n;
	int c;
	char ch;
	do{
		cout<<"select your choice: \n1.write data \n2.read data \n3.append data";
		cin>>c;
		switch(c)
		{
		case 1:{student s[20];
			   cout<<" \n  enter how any students data you want to add";
			   cin>>n;
			   ofstream fout;
			   fout.open("a.txt");
			   for(i=0;i<n;i++)
			   {
				   s[i].getdata();
				   fout.write((char*)&s[i],sizeof(s[i]));
			   }
			   fout.close();
			   break;
			   }
		case 2:{student s1;
			    ifstream fin;
				fin.open("a.txt");
				cout<<"data of students";
				//cout<<"\nname \t roll";
				while(fin.read((char*)&s1,sizeof(s1)))
				{
					s1.putdata();
				}
				fin.close();
				break;
			   }
		case 3:{student s[20];
			   cout<<" \n  enter how any students data you want to add";
			   cin>>n;
			   ofstream fout;
			   fout.open("a.txt",ios::app);
			   for(i=0;i<n;i++)
			   {
				   s[i].getdata();
				   fout.write((char*)&s[i],sizeof(s[i]));
			   }
			   fout.close();
			   break;
			   }
		default:cout<<"invalid choice";
		}cout<<"\ndo you want to continue";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	return(0);
}