#include<iostream>
using namespace std;
class publication
{
 public:
  string title;
  float price;
 void getdata()
 {
  cout<<"\nEnter Title of Book=";
  cin>>title;
  cout <<"\nEnter Price Of Book=";
  cin>>price;
 }
 void putdata()
 {
  cout<<"\nTitle of Book="<<title; 
  cout<<"\nPrice of Book="<<price<<endl;
 }
};

class book:public publication
{
 int pagescount;
 public:
 void getdata_a()
 {
  publication:: getdata();
  cout<<"\nEnter total number of pages=";
  cin>>pagescount;
 }
 void putdata_a()
 {
  publication::putdata();
  cout<<endl;
  cout<<"\nPages of book ="<<pagescount<<endl;
 }
};

class tape: public publication
{
	float time;
	public:
	void getdata_b()
 {
  // publication:: getdate();
  cout<<"\nEnter tape playing time in minutes";
  cin>>time;
 }
 void putdata_b()
 {
 //publication:: putdata();
 cout<<"\nThe whole book is play in "<<time<<" minutes "<<endl;
 cout<<endl;
 }
};

int main()
{
 book a;
 tape b;
 a.getdata_a();
 b.getdata_b();
 a.putdata_a();
 b.putdata_b();
 return (0);
}