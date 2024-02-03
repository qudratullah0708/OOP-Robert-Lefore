#include<iostream>
#include<string>
using namespace std;

struct student
{
	int age;
	string name;
};

void add(student *ss[],int n)
{
	cin>>ss[n]->age;
	cin>>ss[n]->name;
}

void display(student *ss[],int n)
{
	cout<<"\nAge is "<< ss[n]->age;
	cout<<"\nName is "<<ss[n]->name;
}
int main()
{
	student *std[3];
	int n=0;
	for(int i=0; i<2; i++)
	{
		std[i]= new student;
		add(std, n);
		n++;
	}
	for(int i=0; i<n; i++)
	{
		display(std, i);
	}
	for(int i=n; i<3; i++)
	{
		std[i]= new student;
		add(std, n);
		n++;
	}
	for(int i=0; i<3; i++)
	{
		display(std, i);
		n++;
	}
	for(int i=0; i<3; i++)
		delete std[i];
	return 0;
}
