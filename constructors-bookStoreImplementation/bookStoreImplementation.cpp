/*
PROBLEM STATEMENT :
A Book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person inputs the title and author and the system searches the list and displays whether it is available or not. If it is not, an appropriate message is displayed. If it is, then the system displays the book details and requests for the number of copies required. If the requested copies book details and requests for the number of copies required. If the requested copies are available, the total cost of the requested copies is displayed; otherwise the message Required copies not in stock is displayed. Design a system using a class called books with suitable member functions and Constructors. Use new operator in constructors to allocate memory space required. Implement C++ program for the system.
*/

#include<iostream>
#include<string.h>

using namespace std;

class Book
{
	private :

	char* title;
	char* author;
	float price;
	char* publisher;
	int stock;

	public :

	void insertdata();
	void displaydata();
	int search(char[],char[]);
	void getcopies();
	void displayprice(int);

	Book();


};

void Book :: insertdata()
{
	cout<<"\nEnter The Title Of The Book : ";
	cin>>title;
	cout<<"\nEnter The Author Of The Book : ";
	cin>>author;
	cout<<"\nEnter The Price Of The Book : ";
	cin>>price;
	cout<<"\nEnter The Publisher Of The Book : ";
	cin>>publisher;
	cout<<"\nEnter Stock Of The Book : ";
	cin>>stock;
}

void Book :: displaydata()
{
	cout<<"\nThe Title Of The Book Is : ";
	cout<<title;
	cout<<"\nThe Author Of The Book Is : ";
	cout<<author;
	cout<<"\nThe Price Of The Book Is : ";
	cout<<price;
	cout<<"\nThe Publisher Of The Book Is : ";
	cout<<publisher;
	cout<<"\nThe Stock Of The Book Is : ";
	cout<<stock;
}


int Book :: search(char t[20],char a[20])
{
	if((strcmp(title,t)==0)&&(strcmp(author,a)==0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Book :: getcopies()
{
	int c;
	cout<<"\n\nEnter The Number Of Copies You Want To Have : ";
	cin>>c;

	if(c<stock)
	{
		cout<<"\n The Books Are Available ";
		displayprice(c);
	}
	else
	{
		cout<<"\n Stock Not Available, Please Enter Less Copies ";
		getcopies();
	}
}

void Book :: displayprice(int cop)
{
	int pr;
	pr=cop*price;
	cout<<"\n The Amount You Have To Pay Is : "<<pr;
}

Book :: Book()
{
	title=new char[50];
	author=new char[50];
	publisher=new char[50];
	float price=0;
	int stock=0;
}



int main()
{
	Book b[50];

	int op,n;

	cout<<"\n Enter The Options : \n1: Insert Details \n2: Display ";
	cin>>op;

	switch(op)
	{
		case 1:
		cout<<"\n Enter The Number Of Books You Want To Insert : ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"\nEnter The Details For Book "<<i+1<<" : ";
			b[i].insertdata();
		}
		break;

		case 2:
		for(int i=0;i<n;i++)
		{
			cout<<"\nThe Details For Book "<<i+1<<" Are : ";
			b[i].displaydata();
		}
		break;


		default : cout<<"\nExited ";

	}

		int k;
		int count=0;
		char tt[20],at[20];
		cout<<"\nEnter The Title Of The Book You Want To Search : ";
		cin>>tt;
		cout<<"\nEnter The Author Of The Book You Want To Search : ";
		cin>>at;
		for(int j=0;j<n;j++)
		{
			k=b[j].search(tt,at);
			if(k==1)
			{
				cout<<"\n Match Found : ";
				b[j].displaydata();
				b[j].getcopies();
				count++;
			}

		}

		if(count==0)
		{
			cout<<"\n Match Not Found : ";
		}

	return 0;
}


