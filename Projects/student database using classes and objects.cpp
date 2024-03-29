#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;


const int capacity = 70;

#define MAX_SUBJ 5

class student{
private:
	int SerNo;
	int id;
	string name;
	int marks[MAX_SUBJ];
	float prcntge;
	char grade;
	int total_obtain;
public:
	void getData(student s[], int &numStudnets,int i);

	void searchRecord(student s[], int &numStudents);
	
    void appendRecord(student s[], int &numStudents);
	
    void deleteRecord(student s[],int &numStudents);
    
    void updateRecord(student s[],int &numStudents);
    
    void showData(student s[], int &numStudents);
};



  	           
  
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

void student :: getData(student s[],int &numStudents, int i){

		s[i].SerNo=i+1;
    cout<<"Enter the details of student No."<<i+1<<endl;
  do {
  cout << "Enter registration ID between 4500-4800: ";
  cin >>   s[i].id;

  if (s[i].id >= 4500 && s[i].id <= 4800) {
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
    getline(cin, s[i].name);
    cout<<endl;
   
   s[i].total_obtain = 0;
   //student Marks + total
     	 int j;
    for(j=0;j<MAX_SUBJ;j++){
    do {
           cout<<"Enter marks of subject: " <<j+1<<" out of 100: ";
           cin>>s[i].marks[j];
       if  (s[i].marks[j]>=0 && s[i].marks[j]<=100){
       	          // Total marks
       	      s[i].total_obtain = s[i].total_obtain + s[i].marks[j];
       	          // Percentage
       	      s[i].prcntge = ((static_cast<float>(s[i].total_obtain) / 500.0)*100);
       	          //  Grade
       	        if(s[i].prcntge>=80){
       	      	     s[i].grade = 'A';
				 }
			    else if(s[i].prcntge>=70 && s[i].prcntge<80){
       	      	     s[i].grade = 'B';
				 }
				 else if(s[i].prcntge>=60 && s[i].prcntge<70){
       	      	     s[i].grade = 'C';
				 }
				 else if(s[i].prcntge>=50 && s[i].prcntge<60){
       	      	     s[i].grade = 'D';
				 }
				 else if(s[i].grade>=0 && s[i].prcntge<50){
       	      	     s[i].grade = 'F';
				 }
     	break;
     }
        else{
       	    cout << "Invalid Marks"<<endl;
	   }
	 }while(true);
}
    
}

//Searching Record
void student :: searchRecord(student s[],int &numStudents){
int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       bool found = false;
       for(int i=0;i<numStudents;i++){
       	  if(rollno==s[i].id){
       	  	cout<<"Student found\n";
       	  	found = true;
       	  	cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
       	  	cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
       	  	cout<<"\t"<<s[i].SerNo<<"\t"<<s[i].id<<"\t"<<s[i].name<<"\t\t";
   	for(int j=0;j<5;j++){
   		cout<<s[i].marks[j]<<"\t";
	   }
	cout<<s[i].total_obtain<<"\t"<<s[i].prcntge<<"%"<<"\t"<<s[i].grade;
	cout<<endl;
	}
}
            cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
	if(found==false){
   	cout<<"Student Not fo  und\n";
   }
   
}

// Appending new Recordings

void  student :: appendRecord(student s[], int &numStudents){
	

if (numStudents >= capacity) {
        cout << "Cannot add more records. Maximum capacity reached." << endl;
}

      s[numStudents].SerNo = numStudents + 1;
      cout << "Enter registration ID between 4500-4800: ";
      cin >> s[numStudents].id;
      
    cout << "Enter name of student: ";
    cin.ignore(); // Ignore the newline character left in the input buffer
    getline(cin, s[numStudents].name);
    cout<<"Name Taken "<<endl;
 
      s[numStudents].total_obtain = 0;
      for (int j = 0; j < MAX_SUBJ; j++) {
        do {
            cout << "Enter marks of subject " << j + 1 << " out of 100: ";
            cin >> s[numStudents].marks[j];
            if (s[numStudents].marks[j] >= 0 && s[numStudents].marks[j] <= 100) {
                s[numStudents].total_obtain += s[numStudents].marks[j];
                s[numStudents].prcntge = static_cast<float>(s[numStudents].total_obtain) / 500.0 * 100;
                if (s[numStudents].prcntge >= 80) {
                    s[numStudents].grade = 'A';
                }
 else if (s[numStudents].prcntge >= 70 && s[numStudents].prcntge < 80) {
                    s[numStudents].grade = 'B';
                }
                else if (s[numStudents].prcntge >= 60 && s[numStudents].prcntge < 70) {
                    s[numStudents].grade = 'C';
                }
                else if (s[numStudents].prcntge >= 50 && s[numStudents].prcntge < 60) {
                    s[numStudents].grade = 'D';
                }
                else if (s[numStudents].grade >= 0 && s[numStudents].prcntge < 50) {
                    s[numStudents].grade = 'F';
                }
                break;
            }
            else {
                cout << "Invalid Marks. Please enter marks between 0 and 100." << endl;
            }
        }while (true);
        } 
       numStudents++;
       cout << "Record added successfully." << endl;
       
                    // Clear Screen
                    system("cls");
       
        cout<<"\t\t\tBS computer Science Result Spring 2023"<<endl;
    cout<<endl;
    cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
    cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
  
  
   for(int i=0;i<numStudents;i++){
   	cout<<"\t"<<s[i].SerNo<<"\t"<<s[i].id<<"\t"<<s[i].name<<"\t\t";
   	for(int j=0;j<MAX_SUBJ;j++){
   		cout<<s[i].marks[j]<<"\t";
	   }
	cout<<s[i].total_obtain<<"\t"<<s[i].prcntge<<"%"<<"\t"<<s[i].grade;
	cout<<endl;
   }

   cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
}
// Deleting Record
void student :: deleteRecord(student s[], int &numStudents){
		int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       for(int i=0;i<numStudents;i++){
       	  if(rollno==s[i].id){
       	  	cout<<"Student found\n";
       	  	for(int j=i;j<numStudents-1;j++){
       	  		     s[j].id=s[j+1].id;
       	  		     for(int k=0;k<MAX_SUBJ;k++){
       	  		      s[j].marks[k]=s[j+1].marks[k];
					 }
       	  		     
       	  		     s[j].name=s[j+1].name;
       	  		     s[j].prcntge=s[j+1].prcntge;
       	  		     s[j].SerNo=s[j+1].SerNo;
       	  		     s[j].total_obtain=s[j+1].total_obtain;
       	  		     s[j].grade=s[j+1].grade;
				 }
				   // updating array size after deletion
				    numStudents--;
				    
				    // Clear Screen
                    system("cls");
                    
       	  	cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
       	  	
			cout<<"----------------------------------------------------------------------------------------------------"<<endl;
			 for(int i=0;i<numStudents;i++){
       	  	cout<<"\t"<<s[i].SerNo<<"\t"<<s[i].id<<"\t"<<s[i].name<<"\t\t";
   	for(int j=0;j<MAX_SUBJ;j++){
   		cout<<s[i].marks[j]<<"\t";
	   }
	cout<<s[i].total_obtain<<"\t"<<s[i].prcntge<<"%"<<"\t"<<s[i].grade;
	cout<<endl; 	  	  
	}
	cout<<"----------------------------------------------------------------------------------------------------"<<endl; 
	 cout<<"Record Deleted Successfully"<<endl;
}
	else{
   	cout<<"Student Not found\n";
   }
 }
    
}


void student :: updateRecord(student s[],int &numStudents){
	int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       bool found = false;
       for(int i=0;i<numStudents;i++){
       	  if(rollno==s[i].id){
       	  	cout<<"Student found\n";
       	  	found = true;	  
    do {
  cout << "Enter registration ID between 4500-4800: ";
  cin >>   s[i].id;

  if (s[i].id >= 4500 && s[i].id <= 4800) {
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
    getline(cin, s[i].name);
    cout<<endl;
   
   s[i].total_obtain = 0;
   //student Marks + total
     	 int j;
    for(j=0;j<MAX_SUBJ;j++){
    do {
           cout<<"Enter marks of subject: " <<j+1<<" out of 100: ";
           cin>>s[i].marks[j];
       if  (s[i].marks[j]>=0 && s[i].marks[j]<=100){
       	          // Total marks
       	      s[i].total_obtain = s[i].total_obtain + s[i].marks[j];
       	          // Percentage
       	      s[i].prcntge = ((static_cast<float>(s[i].total_obtain) / 500.0)*100);
       	          //  Grade
       	        if(s[i].prcntge>=80){
       	      	     s[i].grade = 'A';
				 }
			    else if(s[i].prcntge>=70 && s[i].prcntge<80){
       	      	     s[i].grade = 'B';
				 }
				 else if(s[i].prcntge>=60 && s[i].prcntge<70){
       	      	     s[i].grade = 'C';
				 }
				 else if(s[i].prcntge>=50 && s[i].prcntge<60){
       	      	     s[i].grade = 'D';
				 }
				 else if(s[i].grade>=0 && s[i].prcntge<50){
       	      	     s[i].grade = 'F';
				 }
     	break;
     }
        else{
       	    cout << "Invalid Marks"<<endl;
	   }
	 }while(true);
   }
   cout<<"Record updated successfully."<<endl;
 }
 
  }
   
    if(found==false){
   	cout<<"Student Not found\n";
   } 
}

// Show Data

void student :: showData(student s[], int &numStudents){
	                // Clear Screen
                    system("cls");
                
    cout<<endl;
    cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
    cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;

// Print Serial Numbers
	for(int i=0;i<numStudents;i++){
		s[i].SerNo=i+1;
	}
  
   for(int i=0;i<numStudents;i++){
   	cout<<"\t"<<s[i].SerNo<<"\t"<<s[i].id<<"\t"<<s[i].name<<"\t\t";
   	for(int j=0;j<MAX_SUBJ;j++){
   		cout<<s[i].marks[j]<<"\t";
	   }
	cout<<s[i].total_obtain<<"\t"<<s[i].prcntge<<"%"<<"\t"<<s[i].grade;
	cout<<endl;
   }

   cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
   
}

int main(){	
 // Creating object s of a student
 cout<<"What's your class strength (Max upto) " <<capacity<<": ";
 int numStudents;
 cin>>numStudents;
 if(numStudents==0){
 	cout<<"No of Students must be between 1 and "<<capacity<<": ";
 	cin>>numStudents;
 }
   student s[capacity];			     
                       cout<<"\t\t\tBS computer Science Result Spring 2023"<<endl;
    cout << "Getting Students Records" << endl;
           // Call the getData function on each student object
              for (int i = 0; i < numStudents; i++) {
                   s[i].getData(s, numStudents,i);
                }
	int choice;
    do {
        displayMenu();
        	cout<<"Enter your choice: ";
            cin>>choice;
        switch (choice) {
            case 1:
                cout << "Searching Record" << endl;
                         s[0].searchRecord(s,numStudents);
                break;
            case 2:
                cout << "Deleting Record" << endl;
                     s[0].deleteRecord(s,numStudents);
                break;
            case 3:
                cout << "Updating Record" << endl;
                s[0].updateRecord(s, numStudents);
                break;
            case 4:
                cout << "Append New Record" << endl;
                    s[0].appendRecord(s, numStudents);
                break;
            case 5:                                   
                cout << "Display Result" << endl;  
				     s[0].showData(s,numStudents);      
                break;
            case 6:                                   
                cout << "Exiting Program" << endl;        
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}