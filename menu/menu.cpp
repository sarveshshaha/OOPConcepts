/*
PROBLEM STATEMENT :
Write a menu driven program that will create a data file containing the list of telephone numbers in the following form

John 23456
Ahmed 98
………..  ………..

Use a class object to store each set of data, access the file created and implement the following tasks
I. Determine the telephone number of specified person
II. Determine the name if telephone number is known
III. Update the telephone number, whenever there is a change
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

class phoneBook
{
    char name[20],phno[6];

    public:
    void getdata();
    void showdata();

    char *getname()
    {
    	return name;
    }

    char *getphno()
    {
    	return phno;
    }

    void update(char *nm,char *telno)
    {
        strcpy(name,nm);
        strcpy(phno,telno);
    }
};

void phoneBook :: getdata()
{
    cout<<"\nEnter Name : ";
    cin>>name;
    cout<<"Enter Phone No. : ";
    cin>>phno;
}

void phoneBook :: showdata()
{
    cout<<"\n";
    cout<<setw(15)<<name;
    cout<<setw(8)<<phno;
}


int main()
{
    phoneBook rec;
    fstream file;
    file.open("phone.dat", ios::ate | ios::in | ios::out | ios::binary);
    char ch,nm[20],telno[6];
    int choice,found=0;

    do
    {

        cout<<"\n*****Phone Book*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Search Telephone No.\n";
        cout<<"4) Search Person Name\n";
        cout<<"5) Update Telephone No.\n";
        cout<<"6) Exit\n";
        cout<<"Choose your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 :
			rec.getdata();
			cin.get(ch);
			file.write((char *) &rec, sizeof(rec));
			break;

            case 2 :
			file.seekg(0,ios::beg);
			cout<<"\n\nRecords in Phone Book\n";
			while(file)
			{
				file.read((char *) &rec, sizeof(rec));
				if(!file.eof())
				{
					rec.showdata();
				}
			}
			file.clear();
			break;

            case 3 :
			cout<<"\n\nEnter Name : ";
			cin>>nm;
			file.seekg(0,ios::beg);
			found=0;
			while(file.read((char *) &rec, sizeof(rec)))
			{
				if(strcmp(nm,rec.getname())==0)
				{
					found=1;
					rec.showdata();
				}
			}
			file.clear();
			if(found==0)
			{
				cout<<"\n\n---Record Not found---\n";
			}
			break;

            case 4 :
			cout<<"\n\nEnter Telephone No : ";
			cin>>telno;
			file.seekg(0,ios::beg);
			found=0;
			while(file.read((char *) &rec, sizeof(rec)))
			{
				if(strcmp(telno,rec.getphno())==0)
				{
					found=1;
					rec.showdata();
				}
			}
			file.clear();
			if(found==0)
			{
				cout<<"\n\n---Record Not found---\n";
			}
			break;

            case 5 :
			cout<<"\n\nEnter Name : ";
			cin>>nm;
			file.seekg(0,ios::beg);
			found=0;
			int cnt=0;

			while(file.read((char *) &rec, sizeof(rec)))
			{
				cnt++;
				if(strcmp(nm,rec.getname())==0)
				{
					found=1;
					break;
				}
			}
			file.clear();
			if(found==0)
			{
				cout<<"\n\n---Record Not found---\n";
			}
			else
			{
				int location = (cnt-1) * sizeof(rec);
				cin.get(ch);
				if(file.eof())
				{
					file.clear();
				}
				cout<<"Enter New Telephone No : ";
				cin>>telno;
				file.seekp(location);
				rec.update(nm,telno);
				file.write((char *) &rec, sizeof(rec));
				file.flush();
			}
			break;
        }
    }while(choice!=6);

    file.close();
    return 0;
}

