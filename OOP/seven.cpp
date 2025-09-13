#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class student
{
 public:
 int r;
 char DOB[10];
 
 int tele;
 char name[10];
 void getdata()
 {
  cout<<"enter the roll number of student";
  cin>>r;
  cout<<"enter the date of birth";
  cin>>DOB;
  cout<<"enter the telephone number";
  cin>>tele;
  cout<<"enter the name";
  cin>>name;
 }
 void putdata()
 {
  
  cout<<"\n"<<r;
  cout<<"\t"<<DOB;
  cout<<"\t"<<tele;
  cout<<"\t"<<name;
 }
 bool operator==(const student &s1)
  {
   return(r==s1.r);
   }
};
vector<student>create()
{
 student s;
 vector<student>temp;
 int n,i;
 cout<<"\n how many student data you want enter";
 cin>>n;
 for(i=0;i<n;i++)
  {
   s.getdata();
   temp.push_back(s);
  }
  return temp;
}
void display(vector<student> temp)
 {
  cout<<"\n data";
  cout<<"\n roll no \tDOB \t telephone \t name";
  for(student i:temp)
   {
    i.putdata();
   }
  }
void search(vector<student> temp)
{
 student s1;
 cout<<"\n enter the roll no to search";
 cin>>s1.r;
 vector<student>::iterator itr;
 itr=find(temp.begin(),temp.end(),s1);
 if(itr==temp.end())
  {
   cout<<"\n record is not found";
  }
 else
   {
    cout<<"\n record found successfully";
    cout<<itr->r<<"\t"<<itr->DOB<<"\t"<<itr->tele<<"\t"<<itr->name;
    }
 }
 bool check1(student &s1,student &s2)
 {
  return(s1.r<s2.r);
 }
 void sorting(vector<student> &temp)
 {
  sort(temp.begin(),temp.end(),check1);
  display(temp);
 }
 void del(vector<student> &temp)
{
 student s;
 cout<<"\n enter the roll no which you want delete";
 cin>>s.r;
 vector<student>::iterator itr;
 itr=find(temp.begin(),temp.end(),s);
 if(itr==temp.end())
  {
   cout<<"\n record is not found";
  }
 else
   {
   temp.erase(itr);
    cout<<"\n record erased successfully";
    display(temp);
    //cout<<itr->r<<"\t"<<itr->DOB<<"\t"<<itr->tele<<"\t"<<itr->name;
    }
 }
 void insert(vector<student> &temp)
 {
  student s;
  s.getdata();
  temp.push_back(s);
  cout<<"\n record inserted";
  display(temp);
 }
 int main()
 {
  vector<student>v;
  int ch;
  char c;
  do{
  cout<<"\n 1.create \n 2.display \n 3.search \n 4.sorting \n 5.delete \n 6.insert";
   cout<<" \n enter your choice";
   cin>>ch;
   
   switch(ch)
    {
     case 1:v=create();
            break;
     case 2:display(v);
            break;
     case 3:search(v);
            break;
     case 4:sorting(v);
            break;
      case 5: del(v);
             break;
      case 6: insert(v);
             break;      
     }
     cout<<"\n do you want to continue";
     cin>>c;
   }while(c=='y');
   return 0;
  }
