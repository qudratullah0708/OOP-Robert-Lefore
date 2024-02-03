#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

const int capacity = 70;

#define MAX_SUBJ 5

class airTime{
	private:
		unsigned int  hr,min,sec;
	public:
		//constructor     
		airTime(int hh=0,int mm=0,int ss=0): hr(hh),min(mm),sec(ss){	}
		
		//airTime():hr(0),min(0),sec(0){}
		//airTime(int hh):hr(hh),min(0),sec(0){}
	//	airTime(int hh,int mm):hr(hh),min(mm),sec(0){}
	//	airTime(int hh,int mm,int ss):hr(hh),min(mm),sec(ss){}
		
		
		//Member Functions
		void timeSetter();
		void displaytime();
		bool operator>(const airTime&TT);
};

void airTime :: timeSetter(){
// hour
	do{
		cout<<"Enter hour: ";
		cin>>hr;
		if(hr>=0 && hr<24){
			break;
		}
		else{
		   cout<<"invalid hour"<<endl;
		}	
	}while(true);
    // minutes
	do{
		cout<<"minutes: ";
	    cin>>min;
		if(min>=0 && min<60){
			break;
		}
		else{
		   cout<<"invalid minutes"<<endl;
		}	
	}while(true);
	// seconds
	do{
		cout<<"seconds: ";
	    cin>>sec; 
		if(sec>=0 && sec<60){
			break;
		}
		else{
		   cout<<"invalid seconds"<<endl;
		}	
	}while(true);
	
}

void airTime :: displaytime(){
//	cout<<"Intime of student "<<endl;
	cout<<hr<<":"<<min<<":"<<sec<<endl;
}

bool airTime :: operator>(const airTime &TT){
	if(hr>TT.hr)
	return true;
	else if((hr==TT.hr)&&(min>TT.min))
	return true;
	else if((hr==TT.hr)&&(min==TT.min)&&(sec>TT.sec))
	return true;
	else
	return false;
}

int main(){
	airTime t2(23,54,56),t1(46,328,64);
	bool res = t1>t2;
	if (res){
		cout<<"valid time";
	}
	else{
		cout<<"Invalid time";
	}
	
}

