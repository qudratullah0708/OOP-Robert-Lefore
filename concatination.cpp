#include<iostream>
#include<string>
using namespace std;

class Mystring{
	private:
	    string s1;
	public:
		// Constructor
		Mystring(string s1=""):s1(s1){}
		// Member Functions
	    void setter();
	    void getter();
	    Mystring operator+(Mystring SS);
};


void Mystring :: setter(){
    cout << "Enter string  ";
    getline(cin, s1);
}


void Mystring :: getter(){
	cout<<"come in getter ";
	cout<<s1;
	cout<<endl;
}

Mystring Mystring :: operator+(Mystring SS){
	Mystring result;
	result.s1= s1+SS.s1;
	return result;
}


int main(){
	Mystring s1,s2,s3;
	 cout << "Concatinate strings" << endl;
                s1.setter();
	            s2.setter();
             	s3 = s1+s2;
	            s3.getter();
}
