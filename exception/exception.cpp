/*
PROBLEM STATEMENT :
Create User defined exception to check the following conditions and throw the exception if the criterion does not met.
a. User has age between 18 and 55
b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4-wheeler

Accept age, Income, City, Vehicle from the user and check for the conditions mentioned above. If any of the condition not met then throw the exception.
*/

#include<iostream>
#include<cstring>

using namespace std;

class exception_handling
{
    int age,income;
    char city[20];
    char Hasvehicle;

    public:
    void getdata()
    {
		cout<<"\n\n Enter Age of Person::";
		cin>>age;
		cout<<"\n\n Enter Income::";
		cin>>income;
		cout<<"\n\n Enter City ::";
		cin>>city;
		cout<<"\n Have 4 Wheeler Vehicle(Y/N)";
		cin>>Hasvehicle;
    }

void putdata()
{
	try
	{
		if(age<18 || age>55)
		{
			throw(1);
		}

		if(income<50000 || income>100000)
		{
			throw(2);
		}

		if((strcmp (city, "Pune" )== 1) || (strcmp (city, "PUNE" )== 1) || (strcmp (city, "pune" )== 1) || (strcmp (city, "Mumbai" )== 1) || (strcmp (city, "mumbai" )== 1) || (strcmp (city, "MUMBAI" )== 1) || (strcmp (city, "Bangalore" )== 1) || (strcmp (city, "BANGALORE" )== 1) || (strcmp (city, "bangalore" )== 1) || (strcmp (city, "Chennai" )== 1) || (strcmp (city, "CHENNAI" )== 1) || (strcmp (city, "chennai" )== 1))
		{
			throw(3);
		}

		if(Hasvehicle=='n' || Hasvehicle=='N')
		{
			throw(4);
		}
	}
	catch(int ex)
	{
		switch(ex)
		{
			case 1:
			cout<<"\n Exception Caught";
			cout<<"\n User's age should be between 18 and 55!!!";
			break;

			case 2:
			cout<<"\n Exception Caught";
			cout<<"\n User should have income between Rs.50,000-Rs.1,00,000 per month!!!";
			break;

			case 3:
			cout<<"\n Exception Caught";
			cout<<"\n User should be from Pune/ Mumbai/ Bangalore / Chennai!!!";
			break;

			case 4:
			cout<<"\n Exception Caught";
			cout<<"\n User should have 4-wheeler!!!";
			break;

			default:
			cout<<"NO EXCEPTION FOUND"<<endl;
		}
	}

	}

};

int main()
{
	int ch;
	exception_handling e1;
	cout<<"\n\t----------Exception Handling----------\n";
	do
	{
		cout<<"\n\n\t 1.Insert data\n\t 2.Check Data \n\t 3.Exit\n";
		cout<<"\nEnter your choice\n";
		cin>>ch;

		switch(ch)
		{
			case 1:
			e1.getdata();
			break;

			case 2:
			e1.putdata();
			break;

			case 3:
			break;

			default:
			cout<<"Enter correct choice";
	}
	}while(ch!=3);

	return 0;
}
