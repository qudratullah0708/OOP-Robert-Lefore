#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

class person{
	private:
		string Name;
		string cnic;
	public:
	   	 virtual void setter();
		 virtual void getter()const;
};

void person :: setter(){
	cout<<"Enter the Employee Name: ";
	getline(cin,Name);
	cout<<endl;
	cout<<"Enter Employee CNIC: ";
	getline(cin,cnic);
}

void person :: getter()const{
	cout<<"The Employee Name: "<<Name;
	cout<<endl;
	cout<<" Employee CNIC: "<<cnic;
}

class Student: virtual public person{
	private:
		string degree;
		float cgpa;
	public:
		void setter();
		void getter()const;
};

void Student :: setter(){
	person :: setter();
	cout<<"Enter degree: ";
	getline(cin,degree);
	cout<<endl;
	cout<<"Enter cgpa: ";
	cin>>cgpa;
}
void Student :: getter()const{
	person :: getter();
	cout<<"Degree: "<<degree;
	cout<<endl;
	cout<<"CGPA: "<<cgpa;
}
class Teacher : virtual public person{
  private:
    string field;
	int no_of_pubs;
  public: 
	void setter();
	void getter()const;
};
void Teacher :: setter(){
	person :: setter();
	cout<<"Enter field: ";
	getline(cin,field);
	cout<<endl;
	cout<<"Enter no_of_pubs: ";
	cin>>no_of_pubs;
}

void Teacher :: getter()const{
	person :: getter();
	cout<<"Field: "<<field;
	cout<<endl;
	cout<<"Enter no_of_pubs: "<<no_of_pubs;
}
int main(){
	person *Pptr = NULL;
	Student s1;
	Pptr = &s1;
	Pptr->setter();
	Pptr->getter();
	
	Teacher t1;
	Pptr = &t1;
	Pptr->setter();
	Pptr->getter();
	
}