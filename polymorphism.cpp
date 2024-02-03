#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

class person{
	protected:
		string Name;
		string cnic;
	public:
	   	 virtual void setter();
		 virtual void getter()const;
};

void person :: setter(){
	cout<<"Enter the Employee Name: ";
	cin.ignore();
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
	protected:
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
  protected:
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
	int count = 0;
		person  *Pptr[MAX];
	do{
		cout<<endl;
		
		cout<<"1. Store data of a new student"<<endl;
		cout<<"2. Store data of a new Teacher"<<endl;
		cout<<"3. Display all"<<endl;
		cout<<"4. Exit"<<endl;
          
		  int choice;
		  cout<<"Enter your choice: ";
		  cin>>choice;
		  switch(choice){
		  	case 1:
		  		Pptr[count] = new Student;
		  		Pptr[count++]->setter();
		  		break;
		  	case 2:
		  		Pptr[count] = new Teacher;
		  		Pptr[count++]->setter();
		  		break;
		  	case 3:
		  		for(int i=0;i<count;i++)
		  			Pptr[i]->getter();
				  break;
			case 4:
				exit(1);
		  }	
	}while(true);	
}