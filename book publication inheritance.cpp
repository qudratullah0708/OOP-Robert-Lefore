	
#include<iostream>
#include<string.h>
using namespace std;

class publication{
	string title;
	float price;
  public:
  	void getdata();
  	void putdata()const;
};
void publication :: getdata(){

	cout<<"Enter the title of a book: ";
	getline(cin,title);
	cout<<endl<<"Enter the price of a book: ";
	cin>>price;
}
void publication :: putdata()const{
	
	cout<<"The title of a book is : "<<title<<endl;
	cout<<"The price of a book is: "<<price<<endl;
}

class book : virtual public publication{
	int page_count;
 public:
 	void getdata();
  	void putdata()const;
};
void book :: getdata(){
	publication :: getdata();
	cout<<"Enter the page_count of a book: ";
	cin>>page_count;
}
void book :: putdata()const{
	publication :: putdata();
	cout<<endl<<"The page_count of a book is: ";
	cout<<page_count;
}

class tape: virtual public publication{
	float minutes;
 public:
 	void getdata();
  	void putdata()const;
};

void tape :: getdata(){
	publication :: getdata();
	cout<<"Enter the play time of a book: ";
	cin>>minutes;
}
void tape :: putdata()const{
   publication :: putdata();
   cout<<"The play time of a book is: ";
   cout<<minutes;
}



int main(){
	book obj;
	obj.getdata();
	obj.putdata();
	tape obj1;
	cin.ignore();
	obj.getdata();
	obj.putdata();
}