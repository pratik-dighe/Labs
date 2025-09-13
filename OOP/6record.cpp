#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class student
{
 public:
 int r, tele;
 char dob[10], name[10];
 void getdata()
 {
  cout<<"enter student name: ";
  cin>>name;
  cout<<"enter student roll no: ";
  cin>>r;
  cout<<"enter date of birth: ";
  cin>>dob;
  cout<<"enter tele no: ";
  cin>>tele;
 }
 void putdata()
 {
  cout<<"\n"<<r;
  cout<<"\t"<<dob;
  cout<<"\t"<<tele;
  cout<<"\t"<<name;
 }
 
 bool operator==(const student &s)
  {
   return(r==s.r);
   }
};

//create
vector<student>create()
{
 student s;
 vector<student>temp;
 int n,i;
 cout<<"\n how many student data you want to store: ";
 cin>>n;
 for(i=0;i<n;i++)
  {
   s.getdata();
   temp.push_back(s);
  }
  return temp;
}

//display
void display(vector<student> temp)
 {
  cout<<"\n data";
  cout<<"\n roll no \tdob \t telephone \t name";
  for(student i:temp)
   {
    i.putdata();
   }
  }
 
 //delete
 void del(vector<student> &temp)
{
 student s;
 cout<<"\n enter roll no to delete: ";
 cin>>s.r;
 vector<student>::iterator itr;
 itr=find(temp.begin(),temp.end(),s);
 if(itr==temp.end())
  {
   cout<<"\n record not found";
  }
 else
   {
   temp.erase(itr);
    cout<<"\n record deleted";
    display(temp);
    }
 }
 
 int main()
 {
  vector<student>v;
  int ch;
  char c;
  do{
  cout<<"\n 1)To create record \n 2)To display record \n 3)To delete record \n";
   cout<<" \n select your choice: ";
   cin>>ch;
   
   switch(ch)
    {
     case 1:v=create();
            break;
     case 2:display(v);
            break;
     case 3:del(v);
             break; 
     }
     cout<<"\nTo continue press y\n";
     cin>>c;
   }while(c=='y');
   return 0;
  }
