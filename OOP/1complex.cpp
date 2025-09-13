#include<iostream>
using namespace std;
class complex
{
	int real, imag;
	public:
	complex()
	{
		real = 0;
		imag = 0;
	}
	
	complex operator +(complex a)
	{
		complex b;
		b.real = real + a.real;
		b.imag = imag + a.imag;
		return(b);
	}

	complex operator *(complex a)
	{
		complex b;
		b.real = (real * a.real);
		b.imag = (imag * a.imag);
		return(b);
	}
      friend istream& operator>>(istream& is, complex &x);
      friend ostream& operator<<(ostream& os, complex &x);
};
istream& operator >>(istream& is, complex &x)
{
	is>>x.real>>x.imag;
	return is;
}

ostream& operator <<(ostream& os,complex &x)
{
	os<< x.real<<"+"<<x.imag<<"i"<<endl;
	return(os);
}

int main()
{
	complex c1, c2, c3, c4;
	cout << "Enter 1st complex number=";
	cin>>c1;
	cout << "Enter 2nd complex number=";
    cin>>c2;
    cout<<"\n1st complex number=";
    cout<<c1;
    cout<<"2nd complex number=";
	cout<<c2;
	c3 = c1 + c2;
	cout<<"Addition=";
	cout<<c3;
	c4 = c1*c2;
	cout << "multiplication=";
	cout<<c4;
	return(0);
}