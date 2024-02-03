#include<iostream>
#include <fstream>
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
		//Member Functions
		void timeSetter();
		void displaytime();
		bool operator>(const airTime&TT);
		// New member functions to get hours, minutes, and seconds
    unsigned int getHours() const { return hr; }
    unsigned int getMinutes() const { return min; }
    unsigned int getSeconds() const { return sec; }
     // Define the setTime function
    void setTime(int hh, int mm, int ss) {
        hr = hh;
        min = mm;
        sec = ss;
    }
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

class student{
private:
	int id;
	string name;
	int marks[MAX_SUBJ];
	float prcntge;
	char grade;
	int total_obtain;
	airTime intime;
	airTime outtime;
public:
	void setter();
    void getter();
	void searchRecord(int rollno);
    bool compareId(int rollno);
    void deleteRecord();
    int getID(int newId){
    	return id;
	}
    // Function to write data to a file
    void writeToFile(ofstream& outFile);
    // Function to read data from a file
    void readFromFile(ifstream& inFile);
    

    
    // to access the private members of class we have declare member functions in public section
     void setIntime() {
     	cout<<"Enter intime of student in 24 hour format "<<endl;
        intime.timeSetter();
    }

    void setOuttime() {
    	cout<<"Enter outtime of student int 24 hour format  "<<endl;
        outtime.timeSetter();
    }

    void showIntime() {
        intime.displaytime();
    }

    void showOuttime() {
        outtime.displaytime();
    }

    bool isOuttimeGreaterThanIntime() {
        return outtime > intime;
    }
};
/// setter----------------
 void student :: setter(){
 	do{
  cout << "Enter registration ID between 4500-4800: ";
  cin >>  id;

  if (id >= 4500 && id <= 4800) {
    break; // Exit the loop
  } 
  else {
    cout << "Invalid ID. "<<endl;
  }
} while (true);
 	
	cout<<endl;
	cin.ignore(); // Ignore the newline character left in the input buffer
	// Student Name
    cout<<"Enter name of student: ";
    getline(cin, name);
    cout<<endl;
   
   total_obtain = 0;
   //student Marks + total
     	 int j;
    for(j=0;j<MAX_SUBJ;j++){
    do {
           cout<<"Enter marks of subject: " <<j+1<<" out of 100: ";
           cin>>marks[j];
       if  (marks[j]>=0 && marks[j]<=100){
       	          // Total marks
       	      total_obtain = total_obtain + marks[j];
       	          // Percentage
       	      prcntge = ((static_cast<float>(total_obtain) / 500.0)*100);
       	          //  Grade
       	        if(prcntge>=80){
       	      	     grade = 'A';
				 }
			    else if(prcntge>=70 && prcntge<80){
       	      	     grade = 'B';
				 }
				 else if(prcntge>=60 && prcntge<70){
       	      	     grade = 'C';
				 }
				 else if(prcntge>=50 && prcntge<60){
       	      	     grade = 'D';
				 }
				 else if(grade>=0 && prcntge<50){
       	      	     grade = 'F';
				 }
     	break;
     }
        else{
       	    cout << "Invalid Marks"<<endl;
	   }
	 }while(true); 
}
     //time setter
	setIntime();
    setOuttime();

    while (!isOuttimeGreaterThanIntime()) {
        cout << "Outtime must be greater than intime " << endl;
        setOuttime();
    }
}

// Getter 
void student :: getter(){
	
	// This function will generate result card

   	cout<<"\t"<<id<<"\t"<<name<<"\t\t";
   	for(int j=0;j<MAX_SUBJ;j++){
   		cout<<marks[j]<<"\t";
	   }
	cout<<total_obtain<<"\t"<<prcntge<<"%"<<"\t"<<grade<<"\t";
	showIntime();
    showOuttime();
}

//Searching Record
void student :: searchRecord(int rollno){
	// Clear Screen
      system("cls");
       bool found = false;
       	  if(rollno==id){
       	  	cout<<"Student found\n";
       	  	found = true;
       	  	cout <<"\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\tInTime\tOutTime\n";
    cout<<"        ----------------------------------------------------------------------------------------------------"<<endl;
       	  	cout<<"\t"<<id<<"\t"<<name<<"\t\t";
   	for(int j=0;j<5;j++){
   		cout<<marks[j]<<"\t";
	   }
	cout<<total_obtain<<"\t"<<prcntge<<"%"<<"\t"<<grade<<"\t";
	showIntime();
    showOuttime();
	cout<<endl;
     cout<<"        ----------------------------------------------------------------------------------------------------"<<endl;
	 }
	if(found==false){
   	cout<<"Student Not found\n";
   }  
               
}


bool student :: compareId(int rollno){
	if(rollno==id){
       	  	cout<<"Student found\n";
       	  	return true;
    }
    return false;
}

void student :: deleteRecord(){
	id=0;
     for(int k=0;k<MAX_SUBJ;k++){
       	  	 marks[k]=0;
     }
       	  		     
	    name="None";
        prcntge=0.0;
       	total_obtain=0;
        grade='\0';              
       	  		     
       	  		    
}

// Function to display the menu
void displayMenu() {
	
    cout << "Menu:" << endl;
    cout << "1. Search Record" << endl;
    cout << "2. Delete Record" << endl;
    cout << "3. Update Record" << endl;
    cout << "4. Append Record" << endl;
    cout << "5. Display Result Card" << endl;
    cout << "6. Quit" << endl;
}


//
void student::writeToFile(ofstream& outFile) {
    outFile << id << " " << name << " ";
    for (int j = 0; j < MAX_SUBJ; j++) {
        outFile << marks[j] << " ";
    }
    outFile << total_obtain << " " << prcntge << " " << grade << " ";

    // Writing intime and outtime
    outFile << intime.getHours() << " " << intime.getMinutes() << " " << intime.getSeconds() << " ";
    outFile << outtime.getHours() << " " << outtime.getMinutes() << " " << outtime.getSeconds() << endl;
}

void student::readFromFile(ifstream& inFile) {
    inFile >> id >> ws; // 'ws' to consume whitespaces
    getline(inFile, name);

    for (int j = 0; j < MAX_SUBJ; j++) {
        inFile >> marks[j];
    }

    inFile >> total_obtain >> prcntge >> grade;

    // Reading intime and outtime
    int inHr, inMin, inSec, outHr, outMin, outSec;
    inFile >> inHr >> inMin >> inSec >> outHr >> outMin >> outSec;

    intime.setTime(inHr, inMin, inSec);
    outtime.setTime(outHr, outMin, outSec);
}

//

int main(){	
 cout<<"What's your class strength (Max upto) " <<capacity<<": ";
 int numStudents;
 cin>>numStudents;
 if(numStudents<=0 && numStudents>capacity){
 	cout<<"No of Students must be between 1 and "<<capacity<<": ";
 	cin>>numStudents;
 }
 // Creating object s of a student
   student s[capacity];		     
                       cout<<"\t\t\tBS computer Science Result Spring 2023"<<endl;
    cout << "Getting Students Records" << endl;
              for (int i = 0; i < numStudents; i++) {
             cout<<"Enter the details of student No."<<i+1<<endl;
                   s[i].setter();
        }
	int choice;
    do {
        displayMenu();
        	cout<<"Enter your choice: ";
            cin>>choice;
        switch (choice) {
            case 1:
                cout << "Searching Record" << endl;
                cout<<"Enter Roll No. ";
                int rollno;
                cin>>rollno;
                for (int i = 0; i < numStudents; i++) {
                	
                         s[i].searchRecord(rollno);
                         break;
                  }
                  for (int i = 0; i < numStudents; i++)
                  if(s[i].compareId(rollno)!=true){
                  	cout<<"Record not found"<<endl;
				  }
                  break;
            case 2:
                cout << "Deleting Record" << endl;
                int roll;
                cout<<"Enter Roll no of student: ";
                cin>>roll;
                for (int i = 0; i < numStudents; i++){
                	if(s[i].compareId(roll)==true){
                		s[i].deleteRecord();
                		cout<<"Record Deleted Successfully"<<endl;
                		break;
				    } 
		        }           
                break;
            case 3:
                cout << "Updating Record" << endl;
                cout<<"Enter Roll No. ";
                cin>>rollno;
                for (int i = 0; i < numStudents; i++) {
                	if (s[i].compareId(rollno)==true){
					s[i].setter();
					cout<<"Record updated Successfully";
					break; 
					}
            }
                     
                break;
            case 4:
                cout << "Append New Record" << endl;
                if (numStudents >= capacity) {
                cout << "Cannot add more records. Maximum capacity reached." << endl;
				}                 
                  else{
                  	s[numStudents].setter();
                  	numStudents++;
                    cout << "Record added successfully." << endl;
				  }
                break;
            case 5:                                   
                cout << "Display Result" << endl;
				// Clear Screen
    system("cls");
                
    cout<<endl;
    cout<<"\t\t\t\tResult Card\t\t\t\t"<<endl<<endl;
    cout <<"\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\tInTime\tOutTime\n";
    cout<<"        ----------------------------------------------------------------------------------------------------"<<endl;  
                for (int i = 0; i < numStudents; i++) {
				     s[i].getter();    
				}
	cout<<"        ----------------------------------------------------------------------------------------------------"<<endl;  
				break;
            case 6:                                   
                cout << "Exiting Program" << endl;        
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    
    ofstream outFile("student_records.txt");
    if (!outFile.is_open(),ios::app) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    // Writing the number of students to the file
    outFile << numStudents << endl;

    // Writing student records to the file
    for (int i = 0; i < numStudents; i++) {
        s[i].writeToFile(outFile);
    }

    outFile.close();

    // ... (unchanged code)

    ifstream inFile("student_records.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    // Reading the number of students from the file
    inFile >> numStudents;

    // Reading student records from the file
    for (int i = 0; i < numStudents; i++) {
        s[i].readFromFile(inFile);
    }

    inFile.close();

    return 0;
}

