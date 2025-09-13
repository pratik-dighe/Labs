#include<iostream>
using namespace std;
  
class Heap
{
	int arr[10];
	int num;
	public:
		Heap(int num)
		{
			this->num=num;
		}
		void insertion();
		void create();
		void Heapify(int n,int i);
		void display();
		void minandmax();
};

void Heap :: insertion()
{
	cout<<"\nEnter marks of "<<num<<" Students :- "<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"student "<<i+1<<": ";
		cin>>arr[i];
	}
}

void Heap:: create()
{
	int i;
	for(i=(num/2)-1;i>=0;i--)
	{
		Heapify(num,i);
	}
	for(i=num-1;i>=1;i--)
	{
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		Heapify(i,0);
	}
}

void Heap :: Heapify(int n,int i)
{
	int large=i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left < n && arr[left] > arr[large])
	{
		large=left;
	}
	if(right < n && arr[right] > arr[large])
	{
		large=right;
	}
		
	if(large != i)
	{
		int temp=arr[i];
		arr[i]=arr[large];
		arr[large]=temp;
		Heapify(n,large);
	}
}

void Heap :: display()
{
	cout<<"\nArray (marks): ";
	for(int i=0 ; i < num ; i++ )
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

void Heap :: minandmax()
{
	cout<<"\nMaximum marks obtain :- "<<arr[num-1]<<endl;
	cout<<"\nMinimum marks obtain :- "<<arr[0]<<endl;
}


int main()
{	
	int num;
	cout<<"\nEnter total number of students :- ";
	cin>>num;
	Heap h(num);
	h.insertion();
	h.create();
	h.display();
	h.minandmax();
	return(0);
}