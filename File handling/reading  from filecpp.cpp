#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

int main(){
	ifstream fin;
	fin.open("myfile.txt");
	char ch;
	//fin>>ch;
	//extraction operator consider white space characters as data seperators and don't read it so we use get() method
	ch = fin.get();
	while(!fin.eof()){
		cout<<ch;
	//	fin>>ch;
	ch = fin.get();
	}
	fin.close();
	getch();
	return 0;
}