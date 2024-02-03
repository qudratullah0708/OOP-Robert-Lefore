#include<iostream>
using namespace std;

class point{
	private:
		int x;
		int y;
	public:
		void move();
		void print();
};


 void point :: move(){
 	cout<<"Enter the value of x ";
 	cin>>x;
 	cout<<endl;
 	cout<<"Enter the value of  y ";
	 cin>>y;
 }
 void point :: print(){
 	cout<<"The value of x is  "<<x<<endl;
 	cout<<"The value of y is " <<y<<endl;
 }
int main(){
	point p1,p2;
	p1.move();
	p1.print();
}