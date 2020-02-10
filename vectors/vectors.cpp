/*
PROBLEM STATEMENT :
Write C++ program using STL for implementation of Singly, doubly and circular linked list.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<iterator>

using namespace std;

class person
{
	private:
	char name[20];
	long tel;
	int age;

	public:
	void getdata()
	{
		cout<<"\nEnter name  ";
		cin>>name;
		cout<<"\nEnter age  ";
		cin>>age;
		cout<<"\nEnter telephone number  ";
		cin>>tel;
	}//getdata

	void showdata()
	{
		cout<<"\n"<<name;
		cout<<"\t"<<age;
		cout<<"\t"<<tel;
	}//showdata

	bool operator==(const person &p)const
	{
		return  p.age==age&&strcmp(p.name,name)==0;
	}

	bool operator<(const person &p)const
	{
		return age<p.age?true:false;
	}
};

int main()
{
	int i,n,m,c;
	person p,per;
	vector<person> v;
	vector<person> ::iterator pr  ;

	do
	{
		cout<<"\n1.Enter the information.\n2.Display the information.\n3.Search a particular person.\n4.Display the list in sorted order.\n5.EXIT";

		cout<<"\nEnter your choice....";
		cin>>c;

		switch(c)
		{
			case 1:
			cout<<"\nEnter the number of person whose information has to be stored ";
			cin>>n;
			for(i=0;i<n;i++)
			{
				cout<<"\nEnter the information of "<<i+1<<" person ";
				p.getdata();
				v.push_back(p);
			}//for
			break;

			case 2:
			cout<<"\nThe information of "<<n<<" people is";
			cout<<"\nName";
			cout<<"\tAge";
			cout<<"\tTelephone no.";

			for(i=0;i<n;i++)
			{
				v[i].showdata();
			}//for

			cout<<endl;
			break;

			case 3:
			cout<<"\nEnter the information of the person that has to be searched";
			per.getdata();
			pr=find(v.begin(),v.end() ,per);
			if(pr!=v.end())
			{
				cout<<"\nSearch Found";
			}
			else
			{
				cout<<"\nSearch Not Found";
			}
			break;

			case 4:
			sort(v.begin(),v.end());
			for(i=0;i<n;i++)
			{
				v[i].showdata();
			}//for

			cout<<"\n";
			break;

			case 5:
			c=5;
			break;

			default:
			cout<<"\nPlease enter correct value......\n";
		}//switch
	}while(c!=5);

	return 0;
}//main
