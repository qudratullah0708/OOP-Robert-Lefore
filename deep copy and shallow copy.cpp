#include<iostream>
using namespace std;
class Dummy{
	int a;
	int b;
	int *p;
  public:
  	Dummy(int x=0,int y=0):a(x),b(y){
	p = new int;
	*p = 0;
	 }
  	void setData(int x,int y,int z){
  		a = x;
  		b = y;
  		*p = z;
	  }
	void showData(){
		cout<<"a = "<<a<<" b = "<<b;
	}
	Dummy(Dummy &d){
		a = d.a;
		b = d.b;
		*p = *(d.p);
	}
	~Dummy(){
		delete p;
	}	  
};

int main(){
    Dummy d1;
	d1.setData(4,5,6);
	Dummy d2;//=d1;
	d2 = d1;
	d2.showData();
}