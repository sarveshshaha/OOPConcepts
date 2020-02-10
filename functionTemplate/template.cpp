/*
PROBLEM STATEMENT :
Write a function template selection Sort. Write a program that inputs, sorts and outputs an int array and a float array.
*/

#include<iostream>

using namespace std;

template <class T>
void s_sort(T a[],int n)
{
     int i,j,t;
     for(i=0;i<n;i++)
     {
    	 for(j=i+1;j<n;j++)
    	 {
    		 if(a[j]<a[i]) //it is in ascending order//for descending order use if(a[j]>a[i])
    		 {
    			 t=a[i];
    			 a[i]=a[j];
    			 a[j]=t;
    		 }
    	 }
     }
}

int main()
{
    int a[100],i,n;
    cout<<"Enter The number of Element:\n";
    cin>>n;

    cout<<"\nEnter Elements:\n";
    for(i=0;i<n;i++)
    {
		cout<<"\nEnter:";
		cin>>a[i];
    }

    s_sort(a,n);

    cout<<"\nAfter Sorting\n";
    for(i=0;i<n;i++)
    {
    	cout<<a[i]<<"\t";
    }

    return 0;
}
