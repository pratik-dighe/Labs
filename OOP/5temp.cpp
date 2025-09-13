#include<iostream>
using namespace std;
int n, A, B;
template<class mytemp>
void selection(mytemp A[10])
{
	int i, j, min;
	//mytemp temp;
	for (i = 0;i <= n - 2;i++)
	{
		min = i;
		for (j = i + 1;j <= n - 1;j++)
		{
			if (A[j] < A[min])
			swap(A[min],A[j]);	
		}
		
	}
	cout << "\nSorted list : \n\n";
	for (i = 0;i < n;i++)
		cout << "\t" << A[i];
}

int main()
{
	int i, A[10];
	float B[10];
	cout << "Template Selection sort";
	cout << "\n\nInteger Array\n";
	cout << "Enter how many elements you want : \n";
	cin >> n;
	cout << "\nEnter the Integer element :\n";
	for (i = 0;i < n;i++)
		cin >> A[i];
	selection(A);
	cout << "\n\nFloat Array\n";
	cout << "Enter how many elements you want : \n";
	cin >> n;
	cout << "\nEnter float element :\n";
	for (i = 0;i < n;i++)
		cin >> B[i];
	selection(B);
	return 0;
}