#include<iostream>
#include<fstream>
using namespace std;
class student 
{
  int roll;
  char name[20];

  
  public:
    void getdata()
      {
       cout<<"\nEnter Roll No of Student=";
       cin>>roll;
       cout<<"\nEnter  Name of Student=";
       cin>>name;
       
      }
     void putdata()
     {
        cout<<"\nRoll No of Student="<<roll;
		cout<<"\nName of Student="<<name;
     }
};
int main()
{
  int i,n,a;
  char choice;
  student s[10];

  cout<<"\n Enter Total No of Students=";
  cin>>n;
do
{
  cout<<"\n1.Write \n2.Read \n3.Append"<<endl;
  cin>>a;
switch(a)
{
case 1:
{
 fstream fout ;
fout.open("student.odt",ios::out);
if(fout.is_open())
{
	cout<<"\nfile is open";              
}
else
{
	cout<<"\n file is closed";
}
for(i=0;i<n;i++)
{
s[i].getdata();
fout.write((char*) &s[i],sizeof(s[i]));
}
fout.close();
}
break;
case 2:
{
fstream fin;
fin.open("student.odt",ios::in);
while(fin.read((char*) &s[i],sizeof(s[i])))
{
	s[i].putdata();               
}
fin.close();}
break;
case 3 :
{
	fstream fapp ;
	fapp.open("student.odt",ios::app);

for(i=0;i<n;i++)
{
s[i].getdata();
fapp.write((char*) &s[i],sizeof(s[i]));
}
fapp.close();
}
break;
default : 
cout<<"\n Invalid Choice : ";
}
cout<<"\n Do you want two continue(y/n) : ";
cin>>choice;
}while(choice=='y');

return 0;

}
