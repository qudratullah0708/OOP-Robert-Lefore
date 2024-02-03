#include<iostream>
using namespace std;

class product{
	int x;
	int y;
 public:
 	void setter(){
 		cout<<"Enter value of x";
 		cin>>x;
 		cout<<"Enter the value of y ";
 		cin>>y;
	 }
	void getter(){
		cout<<"X is "<<x<<" Y is "<<y<<endl;
	}
	int getx(){
		return(x);
	}
	int gety(){
		return(y);
	}
};

class item{
	int a;
	int b;
  public:
  	item(){}
  	item(product p1){
  		a = p1.getx();
  		b = p1.gety();
	  } 
  	void setter(){
  		cout<<"Enter value of a";
 		cin>>a;
 		cout<<"Enter the value of b ";
 		cin>>b;
	  }
	void getter(){
		cout<<"a is "<<a<<" b is "<<b<<endl;
	}
	operator int(){
		return(a,b);
	}

};

int main(){
	product p,p3;
	p.setter();
	item i1,i3;
	i1= p;
	i1.getter();
	p3 = i3;
}