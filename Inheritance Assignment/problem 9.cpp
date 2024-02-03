#include<iostream>
#include<string.h>
using namespace std;

class publication{
	string title;
	float price;
  public:
  	publication(string t="",float p=0):title(t),price(p){}
  	void getdata();
  	void putdata()const;
};
void publication :: getdata(){

	cout<<"Enter the title of a book: ";
	getline(cin,title);
	cout<<"Enter the price of a book: ";
	cin>>price;
}
void publication :: putdata()const{
	
	cout<<"The title of a book is : "<<title<<endl;
	cout<<"The price of a book is: "<<price<<endl;
}

class publication2:virtual public publication{
	private:
		int day;
		int month;
		int year;
		
	public:
		publication2(string t="",float p=0,int d=1,int m=1,int y=2000):publication(t,p),day(d),month(m),year(y){}
		void getdata();
		void putdata()const;
};

void publication2 :: getdata(){
	publication :: getdata();
	cout<<"Enter date of publication of a book:"<<endl;
	cout<<"Enter day no: ";
	cin>>day;
	cout<<"Enter month no: ";
	cin>>month;
	cout<<"Enter year: ";
	cin>>year;
}
void publication2 :: putdata()const{
	publication :: putdata();
	cout<<"Date of publication: "<<day<<"/"<<month<<"/"<<year<<endl;
}


class book : virtual public publication2{
	int page_count;
 public:
 	book(string t="",float p=0,int d=1,int m=1,int y=2000,int pc=0):publication2(t,p,d,m,y),page_count(pc){}
 	void getdata();
  	void putdata()const;
};
void book :: getdata(){
	publication2 :: getdata();
	cout<<"Enter the page_count of a book: ";
	cin>>page_count;
}
void book :: putdata()const{
	publication2 :: putdata();
	cout<<"The page_count of a book is: ";
	cout<<page_count;
}

class tape: virtual public publication2{
	float minutes;
 public:
 	tape(string t="",float p=0,int d=1,int m=1,int y=2000,float mm=0):publication2(t,p,d,m,y),minutes(mm){}
 	void getdata();
  	void putdata()const;
};

void tape :: getdata(){
	publication2 :: getdata();
	cout<<"Enter the play time of a book: ";
	cin>>minutes;
}
void tape :: putdata()const{
   publication2 :: putdata();
   cout<<"The play time of a book is: ";
   cout<<minutes;
}



int main(){
	cout<<"*******Welcome to Books Bazar*******"<<endl;
	book obj;
	obj.getdata();
	obj.putdata();
	tape obj1;
	cin.ignore();
	cout<<endl;
	obj1.getdata();
	obj1.putdata();
}