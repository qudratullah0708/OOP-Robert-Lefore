#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

int main(){
	ofstream fout;
	fout.open("myfile.txt");
	getch();
	fout<<"Masha Allah";
	getch();
	fout.close();
	getch();
}