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

class Sales{
  private:
	float sales[3];
  public:
  	Sales():sales{0, 0, 0}{}
  	void getdata();
  	void putdata()const;
};

void Sales :: getdata(){
	cout<<"Enter the sales of last three months"<<endl;
	for (int i=0;i<3;i++){
		cout<<"Enter the sales of "<<i<<"month: ";
		cin>>sales[i];
	}
}

void Sales :: putdata()const{
	cout<<"Sales of last three months are: "<<endl;
	for (int i=0;i<3;i++){
		cout<<"The sales of "<<i+1<<" month: ";
		cout<<sales[i]<<endl;
	}
}



class book : virtual public publication,virtual public Sales{
	int page_count;
 public:
 	book(string t="",float p=0,int pc=0):publication(t,p),Sales(),page_count(pc){}
 	void getdata();
  	void putdata()const;
};
void book :: getdata(){
	publication :: getdata();
	Sales :: getdata();
	cout<<"Enter the page_count of a book: ";
	cin>>page_count;
}
void book :: putdata()const{
	publication :: putdata();
	Sales :: putdata();
	cout<<endl<<"The page_count of a book is: ";
	cout<<page_count;
}

class tape: virtual public publication,virtual public Sales{
	float minutes;
 public:
 	tape(string s="",float p=0,float m=0):publication(s,p),Sales(),minutes(m){}
 	void getdata();
  	void putdata()const;
};

void tape :: getdata(){
	publication :: getdata();
	Sales :: getdata();
	cout<<"Enter the play time of a book: ";
	cin>>minutes;
}
void tape :: putdata()const{
   publication :: putdata();
   Sales :: putdata();
   cout<<"The play time of a book is: ";
   cout<<minutes;
}




int main(){
	book obj;
	obj.getdata();
	obj.putdata();
	tape obj1;
	cin.ignore();
	cout<<endl;
	obj1.getdata();
	obj1.putdata();
}