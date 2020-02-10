/*
PROBLEM STATEMENT :
Write C++ program using STL for Dqueue (Double ended queue).
*/

#include<iostream>
#include<iterator>
#include<list>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

template<class T>
void pushelements(T &stackref)
{
	for(int i=0;i<10;i++)
	{
		stackref.push(i);
		cout<<"\t"<<stackref.top();
	}//for
}

template<class T>
void popelements(T &stackref)
{
	cout<<"\n";
	while(!stackref.empty())
	{
		cout<<"\t"<<stackref.top();
		stackref.pop();
	}//while
}

template<class T>
void pushelement(T &stackref)
{
	for(int i=0;i<10;i++)
	{
		stackref.push(i);
		cout<<"\t"<<stackref.back();
	}//for
}

template<class T>
void popelement(T &stackref)
{
	cout<<"\n";
	while(!stackref.empty())
	{
		cout<<"\t"<<stackref.front();
		stackref.pop();

	}//while
}


int main()
{
	stack< int , list <int> > liststack;
	queue<int ,list<int> >q;

	cout<<"\nPushing elements on stack...\n";
	pushelements(liststack);
	cout<<"\nPopping elements from stack....";
	popelements(liststack);
	cout<<"\nPushing elements on queue...\n";
	pushelement(q);
	cout<<"\nPopping elements on queue...\n";
	popelement(q);

	return 0;
}
