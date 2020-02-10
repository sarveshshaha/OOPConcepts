/*
PROBLEM STATEMENT :
Implement a class Complex which represents the Complex Number data type. Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.
*/
#include<iostream>

using namespace std;

class Complex
{
	private :

	int real;
	int imaginary;

	public :

	Complex();
	Complex(int,int);
	Complex operator+(Complex);
	Complex operator-(Complex);
	Complex operator*(Complex);
	friend ostream& operator<<(ostream&,Complex);
	friend istream& operator>>(istream&,Complex&);

};

Complex :: Complex()
{
	real=0;
	imaginary=0;
}

Complex :: Complex(int re,int im)
{
	real=re;
	imaginary=im;
}

Complex Complex :: operator+(Complex c1)
{
		Complex temp;

		temp.real=real+c1.real;

		temp.imaginary=imaginary+c1.imaginary;

		return temp;
}

Complex Complex :: operator*(Complex c1)
{
		Complex temp;

		temp.real=real*c1.real;

		temp.imaginary=imaginary*c1.imaginary;

		return temp;
}


Complex Complex :: operator-(Complex c2)
{
		Complex temp;

		temp.real=real-c2.real;

		temp.imaginary=imaginary-c2.imaginary;

		return temp;
}

ostream& operator<<(ostream& out,Complex c)
{
	out<<c.real<<" + "<<c.imaginary<<"i";
	return out;
}

istream& operator>>(istream& in,Complex &c)
{
	cout<<"\n Enter The Real Part : ";
	in>>c.real;
	cout<<"\n Enter The Imaginary Part : ";
	in>>c.imaginary;
	return in;
}

int main()
{
	Complex c1,c2,sum,diff,mul;
	int op;
	char c;

	cout<<"\n Enter Two Complex Numbers You Want To Perform Operations On : ";
	cin>>c1;
	cin>>c2;

	cout<<"\n Enter The Option Of Operation You Want To Perform : \n1:Addition \n2:Subtraction \n3:Multiplication \n";
	cin>>op;

	do
	{
		switch(op)
		{
			case 1:
			{
				sum=c1+c2;
				cout<<"\n Sum Is : ";
				cout<<sum;
				break;
			}

			case 2:
			{
				diff=c1-c2;
				cout<<"\n Difference Is : ";
				cout<<diff;
				break;
			}

			case 3:
			{
				mul=c1*c2;
				cout<<"\n Multiplication Is : ";
				cout<<mul;
				break;
			}

			default : cout<<"\n Wrong Option Entered : ";
		}

		cout<<"\n Do You Want To Continue (Y/N)?\n";
		cin>>c;

	}while((c=='y')||(c=='Y'));

	return 0;
}

