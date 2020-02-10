/*
PROBLEM STATEMENT :
Create employee bio-data using following classes i) Personal record ii))Professional record iii) Academic record Assume appropriate data.  members and member function to accept required data & print bio-data. Create bio-data using multiple inheritance using C++.
*/

#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

class personal//Personal Information
{
	private:
	char name[30];
	char sname[30];
	int age;
	int height;

	public:

	void getpersonal()
	{
		cout<<"\tEnter the name=>";
		cin>>name;
		cout<<"\tEnter the surname=>";
		cin>>sname;
		cout<<"\n\tEnter the age=>";
		cin>>age;
		cout<<"\n\tEnter the height=>";
		cin>>height;
	}

	void putpersonal()
	{
		cout<<"\n\tName=>"<<name<<" "<<sname;
		cout<<"\n\tAge=>"<<age;
		cout<<"\n\tHeight=>"<<height;
	}
};

class proffesional//Proffesional Info
{
	private:
	char c1[30];
	int year;

	public:

	void getpro()
	{
		cout<<"\n\tEnter the company name u work in";
		cin>>c1;
		cout<<"\n\tEnter year of expirence";
		cin>>year;
	}

	void putpro()
	{
		cout<<"\n\tThe company name u work in ";
		cout<<c1;
		cout<<"\n\tYear of expirence "<<year;
	}
};

class acd//Academic Info
{
	private:
	char school[30];
	char college[30];
	int mark10;
	int mark12;
	int markc;

	public:
	void getacd()
	{
		cout<<"\n\tEnter the name of School=>";
		cin>>school;
		cout<<"\n\tEnter the college name=>";
		cin>>college;
		cout<<"\n\tEnter the Marks of 10th class ";
		cin>>mark10;
		cout<<"\n\tEnter the Marks of 12th class ";
		cin>>mark12;
		cout<<"\n\tEnter the Marks of college ";
		cin>>markc;
	}

	void putacd()
	{
		 cout<<"\n\tThe name of School=>";
		puts(school);
		cout<<"\n\tThe college name=>";
		cout<<college;
		cout<<"\n\tThe Marks of 10th class\t"<<mark10;
		cout<<"\n\tThe Marks of 12th class\t"<<mark12;
		cout<<"\n\tThe Marks of college\t"<<markc;
	}
};

class biodata : public personal,public proffesional,public acd
{
	public:

	void get()
	{
		getpersonal();
		getpro();
		getacd();
	}

	void put()
	{
		putpersonal();
		putpro();
		putacd();
	}
};

int main()
{
	biodata s1;
	int ch,flag=0;

	do
	{
		cout<<"\n\t1)Enter the details";
		cout<<"\n\t2)Display the details";
		cout<<"\n\t3)Exit\n";
		cin>>ch;

		switch(ch)
		{
			case 1:
			flag=1;
			s1.get();
			break;

			case 2:
			if(flag==1)
			{
				s1.put();
			}
			else
			{
			  cout<<"\nEnter the details first in case 1";
			}
			break;
		}
	}while(ch!=3);

 return 0;
}
