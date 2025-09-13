#include<iostream>
#include<map>
using namespace std;
int main()
{
	int i,n,pop;
	string state,s;
	map<string,int>mymap;
	cout<<"enter number of states you want to store: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter name of state: ";
		cin>>state;
		cout<<"enter population of "<<state<<": ";
		cin>>pop;
		mymap.insert(make_pair(state,pop));
	}
	cout<<"states	population";
	for(auto itr=mymap.begin();itr!=mymap.end();itr++)
	{
		cout<<"\n"<<itr->first<<"\t"<<itr->second;
	}
	cout<<"\nenter state to be searched: ";
	cin>>s;
	int flag=0;
	for(auto itr=mymap.begin();itr!=mymap.end();itr++)
	{
		if(itr->first==s)
		{
			cout<<"population of "<<s<<"is "<<itr->second;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"state not found";
	}
	return 0;
}