#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<string,int>mymap;
	int p;
	cout<<"enter how many states can store";
	cin>>p;
	string state;
	int pop;
	for(int i=0;i<p;i++)
	{
	cout<<"enter name of state"<<endl;
	cin>>state;
	cout<<"enter population of state"<<endl;
	cin>>pop;
	mymap.insert(make_pair(state,pop));
	}

	
string s;
cout<<"Enter the state name which we can retrive in map"<<endl;
cin>>s;
int flag=0;
for(auto itr=mymap.begin();itr!=mymap.end();itr++)
{
	if(itr->first==s)
	{
	cout<<itr->first<<" population is->"<<itr->second<<endl;
	flag=1;
	break;
	}
}
if(flag==0)
{
	cout<<"the state is not found"<<endl;
}
return 0;
}	
