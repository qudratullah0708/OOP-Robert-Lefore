#include<iostream>
#include<string.h>
using namespace std;

class emp{
	private:
		int empNum;
		string empName;
	public:
		emp(int id=0,string nm=""):empNum(id),empName(nm){}
		virtual void isoutstanding()=0;
	      void setter();
		void getter()const;
};


class manager:public emp{
	private:
		string title;
		float club_dues;
	public:
		void isoutstanding(){
			cout<<"This is very outstanding";
		}
		manager(int id=0,string nm="",string t="",float cd=0.0):emp(id,nm),title(t),club_dues(cd){}
		void setter();
		void getter()const;
};

class scientist : public emp{
  private:
    string field;
	int no_of_pubs;
  public: 
    scientist(int id=0,string nm="",string f="",int np=0):emp(id,nm),field(f),no_of_pubs(np){}
	void setter();
	void getter()const;
	void isoutstanding();
};
	
		

class labour : public emp{
    private:
	char shift;
	float hrs_worked;
	public:
	labour(int id=0,string nm="",char sh='m',float hw=0):emp(id,nm),shift(sh),hrs_worked(hw){}
	void setter();
	void getter()const;
		void isoutstanding(){
		cout<<"This is outstanding";
	}
};


void emp :: setter(){
	cout<<"Enter the Employee No: ";
	cin>>empNum;
	cout<<endl;
	cout<<"Enter Employee Name: ";
	cin>>empName;
}

void emp :: getter()const{
	cout<<"_____________Employee Details_____________"<<endl;
	cout<<"Employee No: "<<empNum<<endl;
	cout<<"Employee Name: "<<empName<<endl;
}

void manager :: setter(){
	 emp :: setter();
	cout<<"Enter the Title of a Manager: ";
	cin>>title;
	cout<<endl;
	cout<<"Enter the club_dues: ";
	cin>>club_dues;
}

void manager :: getter()const{
	 emp :: getter();
	cout<<"Employee Title: "<<title<<endl;
	cout<<"Employee club_dues: "<<club_dues<<endl;
}



void scientist :: setter(){
	emp :: setter();
	cout<<"Enter the Field of a scientist: ";
	cin>>field;
	cout<<endl;
	cout<<"Enter the no_of_pubs: ";
	cin>>no_of_pubs;
	void isoutstanding(){
		if(no_of_pubs>=10)
		cout<<"This is outstanding";
	}
}

void scientist :: getter()const{
	 emp :: getter();
	cout<<"Employee field: "<<field<<endl;
	cout<<"Employee no_of_pubs: "<<no_of_pubs<<endl;
}


void labour :: setter(){
	emp :: setter();
	cout<<"Enter the shift of a labour: ";
	cin>>shift;
	cout<<endl;
	cout<<"Enter the no_of_hrs_worked: ";
	cin>>hrs_worked;
}

void labour :: getter()const{
	 emp :: getter();
	cout<<"Labour shift: "<<shift<<endl;
	cout<<"Hours worked: "<<hrs_worked<<endl;
}
int main(){
	manager m1(1,"Ali","PM",3074.8);
	m1.getter();

	scientist s1(2,"Nouman","Developer",05);
	s1.getter();
	labour r1(3,"Arslan",'E',5.6);
	r1.getter();
}