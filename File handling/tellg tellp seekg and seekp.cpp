#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

//seekg() is used to move the get pointer to a desired location 
//seekp() is used to move the put pointer to a desired location
// tellp() is used to know where the put pointer is in a file.
// tellg() is used to know where the get pointer is in a file.

/*
   the “get” position (for reading)
   the “put” position (for writing)
*/

int main(){
  ifstream fin;
  fin.open("myfile.txt");
  cout<<fin.tellg();
  cout<<"\n"<<(char)fin.get();
   cout<<(char)fin.get();
   cout<<"\n"<<fin.tellg();
   
   // second argument is optional
   fin.seekg(2,ios_base::beg);
   cout<<"\n"<<fin.tellg();
   fin.seekg(2,ios_base::curr);
   cout<<"\n"<<fin.tellg();
   fin.seekg(-3,ios_base::end);
   cout<<"\n"<<fin.tellg();
   cout<<"\n"<<(char)fin.get();
   getch();
   
   // same is the scenario with seekp and tellp but used it with object of ofstream
}