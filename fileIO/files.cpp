/*
PROBLEM STATEMENT :
Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file.
*/

#include<fstream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	char c,u;
	char fname[10];
	ofstream out;

	cout<<"Enter File Name:";
	cin>>fname;
	out.open(fname);

	cout<<"Enter the text(Enter # at end)\n";   //write contents to file
	while((c=getchar())!='#')
	{
		out<<c;
	}

	out.close();

	ifstream in(fname);        //read the contents of file
	cout<<"\n\n\t\tThe File contains\n\n";
	while(in.eof()==0)
	{
		in.get(c);
		cout<<c;
	}

    return 0;

}
