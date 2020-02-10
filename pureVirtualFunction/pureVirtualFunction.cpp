/*
PROBLEM STATEMENT :
Write C++ Program with base class convert declares two variables, val1 and val2, which hold the initial and converted values, respectively. It also defines the functions getinit( ) and getconv( ), which return the initial value and the converted value. These elements of convert are fixed and applicable to all derived classes that will inherit convert. However, the function that will actually perform the conversion, compute( ), is a pure virtual function that must be defined by the classes derived from convert. The specific nature of compute( ) will be determined by what type of conversion is taking place.
*/

#include<iostream>

using namespace std;

class convert
{
	protected:
	float a,b;

	public :

	void siv(float x)
	{
		a=x;
	}

	float giv()
	{
		return a;
	}

	float gcv()
	{
		return b;
	}

	virtual void c(){}
};

class dc: public convert
{
	public:
	void c()
	{
		b=(a/100);
	}

	void d()
	{
		b=(a*(9/5))+32;
	}

	void e()
	{
		b=a*60;
	}
};

int main()
{

	dc dist;
	float val;
	cout<<"\nEnter the amount to covert(cm to m)";
	cin>>val;
	dist.siv(val);

	dist.c();
	cout<<"\nInitial value="<<dist.giv();
	cout<<"\nCoverted value="<<dist.gcv();

	cout<<"\nEnter the amount to covert(C to F)";
	cin>>val;
	dist.siv(val);

	dist.d();
	cout<<"\nInitial value="<<dist.giv();
	cout<<"\nCoverted value="<<dist.gcv();

	cout<<"\nEnter the amount to covert(Hr to Min)";
	cin>>val;
	dist.siv(val);

	dist.e();
	cout<<"\nInitial value="<<dist.giv();
	cout<<"\nCoverted value="<<dist.gcv();

	return 0;
}

