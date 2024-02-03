#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;
const int capacity = 70;
struct student{
	int SerNo;
	int id;
	string name;
	int marks[5];
	float prcntge;
	char grade;
	int total_obtain;
} ;
// Function to display the menu
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Search Record" << endl;
    cout << "2. Delete Record" << endl;
    cout << "3. Update Record" << endl;
    cout << "4. Append Record" << endl;
    cout << "5. Display Result Card" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter your choice: ";
}
// GetData Function
void getData(student *ilptr[], int &numStudents) {
    for (int i = 0; i < numStudents; i++) {
        ilptr[i]->SerNo = i + 1;
    }
    
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the details of student No." << i + 1 << endl;
        
        do {
            cout << "Enter registration ID between 4500-4800: ";
            cin >> ilptr[i]->id;

            if (ilptr[i]->id >= 4500 && ilptr[i]->id <= 4800) {
                break; // Exit the loop
            } else {
                cout << "Invalid ID." << endl;
            }
        } while (true);

        cout << endl;
        cin.ignore(); // Ignore the newline character left in the input buffer
        
        // Student Name
        cout << "Enter name of student: ";
        getline(cin, ilptr[i]->name);
        cout << endl;

        ilptr[i]->total_obtain = 0;
        
        // Student Marks + total
        int j;
        for (j = 0; j < 5; j++) {
            do {
                cout << "Enter marks of subject " << j + 1 << " out of 100: ";
                cin >> ilptr[i]->marks[j];
                if (ilptr[i]->marks[j] >= 0 && ilptr[i]->marks[j] <= 100  ) {
                    // Total marks
                    ilptr[i]->total_obtain = ilptr[i]->total_obtain + ilptr[i]->marks[j];
                    // Percentage
                    ilptr[i]->prcntge = ((static_cast<float>(ilptr[i]->total_obtain) / 500.0) * 100);
                    // Grade
                    if (ilptr[i]->prcntge >= 80) {
                        ilptr[i]->grade = 'A';
                    } else if (ilptr[i]->prcntge >= 70 && ilptr[i]->prcntge < 80) {
                        ilptr[i]->grade = 'B';
                    } else if (ilptr[i]->prcntge >= 60 && ilptr[i]->prcntge < 70) {
                        ilptr[i]->grade = 'C';
                    } else if (ilptr[i]->prcntge >= 50 && ilptr[i]->prcntge < 60) {
                        ilptr[i]->grade = 'D';
                    } else if (ilptr[i]->grade >= 0 && ilptr[i]->prcntge < 50) {
                        ilptr[i]->grade = 'F';
                    }
                    break;
                } else {
                    cout << "Invalid Marks" << endl;
                }
            } while (true);
        }
    }
}


//Searching Record
void searchRecord(student *s[],int &numStudents){
int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       for(int i=0;i<numStudents;i++){
       	  if(rollno==s[i]->id){
       	  	cout<<"Student found\n";
       	  	cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
       	  	cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
       	  	cout<<"\t"<<s[i]->SerNo<<"\t"<<s[i]->id<<"\t"<<s[i]->name<<"\t\t";
   	for(int j=0;j<5;j++){
   		cout<<s[i]->marks[j]<<"\t";
	   }
	cout<<s[i]->total_obtain<<"\t"<<s[i]->prcntge<<"%"<<"\t"<<s[i]->grade;
	cout<<endl;
	}
	else{
   	cout<<"Student Not found\n";
   }
}
   
}

// Appending new Recordings

void appendRecord(student *s[], int &numStudents){
	

if (numStudents >= capacity) {
        cout << "Cannot add more records. Maximum capacity reached." << endl;
}
      s[numStudents]->SerNo = numStudents + 1;

      cout << "Enter registration ID between 4500-4800: ";
      cin >> s[numStudents]->id;

    cin.ignore(); // Ignore the newline character left in the input buffer
    cout << "Enter name of student: ";
    getline(cin, s[numStudents]->name);
 
      s[numStudents]->total_obtain = 0;
      for (int j = 0; j < 5; j++) {
        do {
            cout << "Enter marks of subject " << j + 1 << " out of 100: ";
            cin >> s[numStudents]->marks[j];
            if (s[numStudents]->marks[j] >= 0 && s[numStudents]->marks[j] <= 100) {
                s[numStudents]->total_obtain += s[numStudents]->marks[j];
                s[numStudents]->prcntge = static_cast<float>(s[numStudents]->total_obtain) / 500.0 * 100;
                if (s[numStudents]->prcntge >= 80) {
                    s[numStudents]->grade = 'A';
                }
 else if (s[numStudents]->prcntge >= 70 && s[numStudents]->prcntge < 80) {
                    s[numStudents]->grade = 'B';
                }
                else if (s[numStudents]->prcntge >= 60 && s[numStudents]->prcntge < 70) {
                    s[numStudents]->grade = 'C';
                }
                else if (s[numStudents]->prcntge >= 50 && s[numStudents]->prcntge < 60) {
                    s[numStudents]->grade = 'D';
                }
                else if (s[numStudents]->grade >= 0 && s[numStudents]->prcntge < 50) {
                    s[numStudents]->grade = 'F';
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
       
       
       
        cout<<"\t\t\tBS computer Science Result Spring 2023"<<endl;
    cout<<endl;
    cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
    cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
  
  
   for(int i=0;i<numStudents;i++){
   	cout<<"\t"<<s[i]->SerNo<<"\t"<<s[i]->id<<"\t"<<s[i]->name<<"\t\t";
   	for(int j=0;j<5;j++){
   		cout<<s[i]->marks[j]<<"\t";
	   }
	cout<<s[i]->total_obtain<<"\t"<<s[i]->prcntge<<"%"<<"\t"<<s[i]->grade;
	cout<<endl;
   }

   cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
   
   

}
// Deleting Record
void deleteRecord(student *s[], int &numStudents){
		int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       for(int i=0;i<numStudents;i++){
       	  if(rollno==s[i]->id){
       	  	cout<<"Student found\n";
       	  	for(int j=i;j<numStudents-1;j++){
       	  		     s[j]->id=s[j+1]->id;
       	  		     for(int k=0;k<5;k++){
       	  		      s[j]->marks[k]=s[j+1]->marks[k];
					 }
       	  		     
       	  		     s[j]->name=s[j+1]->name;
       	  		     s[j]->prcntge=s[j+1]->prcntge;
       	  		     s[j]->SerNo=s[j+1]->SerNo;
       	  		     s[j]->total_obtain=s[j+1]->total_obtain;
       	  		     s[j]->grade=s[j+1]->grade;
				 }
				   // updating array size after deletion
				    numStudents--;
       	  	cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
       	  	
			cout<<"----------------------------------------------------------------------------------------------------"<<endl;
			 for(int i=0;i<numStudents;i++){
       	  	cout<<"\t"<<s[i]->SerNo<<"\t"<<s[i]->id<<"\t"<<s[i]->name<<"\t\t";
   	for(int j=0;j<5;j++){
   		cout<<s[i]->marks[j]<<"\t";
	   }
	cout<<s[i]->total_obtain<<"\t"<<s[i]->prcntge<<"%"<<"\t"<<s[i]->grade;
	cout<<endl;
       	  	   
       	  	   cout<<"Record Deleted Successfully"<<endl;
	}
}
	else{
   	cout<<"Student Not found\n";
   }
}
    
}


// Show Data

void showData(student *s[], int &numStudents){
	                // Clear Screen
                    system("cls");
                
    cout<<endl;
    cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
    cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;

// Print Serial Numbers
	for(int i=0;i<numStudents;i++){
		s[i]->SerNo=i+1;
	}
  
   for(int i=0;i<numStudents;i++){
   	cout<<"\t"<<s[i]->SerNo<<"\t"<<s[i]->id<<"\t"<<s[i]->name<<"\t\t";
   	for(int j=0;j<5;j++){
   		cout<<s[i]->marks[j]<<"\t";
	   }
	cout<<s[i]->total_obtain<<"\t"<<s[i]->prcntge<<"%"<<"\t"<<s[i]->grade;
	cout<<endl;
   }

   cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
   
}




int main(){	
 // Creating object s of a student
 cout<<"Enter number of students in your class: ";
 int numStudents;
 cin>>numStudents;
 /*
  It seems that you are trying to pass an array of pointers to student structures to the getData function, 
  but you haven't allocated memory for the individual student objects in the array.
 To fix this issue, you need to allocate memory for each student before passing them to getData.
 */
  // Allocate memory for each student
    student* s[numStudents];
    for (int i = 0; i < numStudents; i++) {
        s[i] = new student;
    }		
	/////////////////////////////////////////////////////////////     
        cout<<"\t\t\tBS computer Science Result Spring 2023"<<endl;
                       
    cout << "Getting Students Records" << endl;
           getData(s,numStudents);
           cin.ignore();
	int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Searching Record" << endl;
                         searchRecord(s,numStudents);
                break;
            case 2:
                cout << "Deleting Record" << endl;
                     deleteRecord(s,numStudents);
                break;
            case 3:
                cout << "Updating Record" << endl;
                break;
            case 4:
                cout << "Append New Record" << endl;
                     appendRecord(s,numStudents);
                break;
            case 5:                                   
                cout << "Display Result" << endl;  
				     showData(s,numStudents);      
                break;
            case 6:                                   
                cout << "Exiting Program" << endl;        
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    
    // Deallocate memory for each student
    for (int i = 0; i < numStudents; i++) {
        delete s[i];
    }

    return 0;
}