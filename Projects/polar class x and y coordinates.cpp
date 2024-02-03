#include<iostream>
using namespace std;

class Polar{
  private:
	int X;
	int Y;
  public:
    Polar(int x=0,int y=0):X(x),Y(y){};
  	void setter();
  	Polar operator+(Polar PP);
  	void getter(Polar PP);
};

void Polar :: setter(){
	cout<<"Setting values for coordinates of P1: "<<endl;
	cout<<"Enter X coordinate: ";
	cin>>X;
	cout<<endl;
	cout<<"Enter Y coordinate: ";
	cin>>Y;
}


Polar Polar :: operator+(Polar PP){
	Polar result;
	result.X = X+PP.X;
	result.Y = Y+PP.Y;
	return result;
}

void Polar :: getter(Polar PP){
	cout<<"The value of X coordinate is "<<PP.X<<endl;
	cout<<"The value of Y coordinate is "<<PP.Y;
}
int main(){
	Polar p1,p2,p3;
	p1.setter();
	p2.setter();
	p3=p1+p2;
	p3.getter(p3);
}