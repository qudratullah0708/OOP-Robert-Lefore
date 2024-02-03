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
	student*next;
	
  public:
  	void getData(student *head, int &numStudnets,int i);

	void searchRecord(student *head,int &numStudents);
	
    void appendRecord(student *head,int &numStudents);
	
    student*  deleteRecord(student *head,int &numStudents);
    
    void updateRecord(student *head,int &numStudents);
    
    void showData(student *head,int &numStudents);
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
}
// GetData Function
void student :: getData(student *head, int &numStudents,int i) {
	 student*temp = head;
	
    	temp->SerNo = i + 1;
        cout << "Enter the details of student No." << i + 1 << endl;
        
        do {
            cout << "Enter registration ID between 4500-4800: ";
            cin >> temp->id;

            if (temp->id >= 4500 && temp->id <= 4800) {
                break; // Exit the loop
            } else {
                cout << "Invalid ID." << endl;
            }
        } while (true);

        cout << endl;
        cin.ignore(); // Ignore the newline character left in the input buffer
        
        // Student Name
        cout << "Enter name of student: ";
        getline(cin, temp->name);
        cout << endl;

        temp->total_obtain = 0;
        
        // Student Marks + total
        int j;
        for (j = 0; j < MAX_SUBJ; j++) {
            do {
                cout << "Enter marks of subject " << j + 1 << " out of 100: ";
                cin >> temp->marks[j];
                if (temp->marks[j] >= 0 && temp->marks[j] <= 100  ) {
                    // Total marks
                    temp->total_obtain = temp->total_obtain + temp->marks[j];
                    // Percentage
                    temp->prcntge = ((static_cast<float>(temp->total_obtain) / 500.0) * 100);
                    // Grade
                    if (temp->prcntge >= 80) {
                        temp->grade = 'A';
                    } else if (temp->prcntge >= 70 && temp->prcntge < 80) {
                        temp->grade = 'B';
                    } else if (temp->prcntge >= 60 && temp->prcntge < 70) {
                        temp->grade = 'C';
                    } else if (temp->prcntge >= 50 && temp->prcntge < 60) {
                        temp->grade = 'D';
                    } else if (temp->grade >= 0 && temp->prcntge < 50) {
                        temp->grade = 'F';
                    }
                    break;
                } else {
                    cout << "Invalid Marks" << endl;
                }
            } while (true);
        }
}


//Searching Record
void student :: searchRecord(student*head,int &numStudents){
int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       bool found = false;
        student*temp = head;
       while(temp!=NULL){
       	  if(rollno==temp->id){
       	  	cout<<"Student found\n";
       	  	found = true;
       	  	cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
       	  	cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
       	  	cout<<"\t"<<temp->SerNo<<"\t"<<temp->id<<"\t"<<temp->name<<"\t\t";
   	for(int j=0;j<5;j++){
   		cout<<temp->marks[j]<<"\t";
	   }
	cout<<temp->total_obtain<<"\t"<<temp->prcntge<<"%"<<"\t"<<temp->grade;
	cout<<endl; 
	break;
	}
	else{
		temp = temp->next;	
   }
}
   if(!found){
   	cout<<"Student Not found\n";
   }
}
//--------------------------------------------------------------

// Update data 
void student :: updateRecord(student *head, int &numStudents) {
	
	int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       bool found = false;
       student*temp = head;
       while(temp!=NULL){
       	  if(rollno==temp->id){    
        do {
            cout << "Enter registration ID between 4500-4800: ";
            cin >> temp->id;

            if (temp->id >= 4500 && temp->id <= 4800) {
                break; // Exit the loop
            } else {
                cout << "Invalid ID." << endl;
            }
        } while (true);

        cout << endl;
        cin.ignore(); // Ignore the newline character left in the input buffer
        
        // Student Name
        cout << "Enter name of student: ";
        getline(cin, temp->name);
        cout << endl;

        temp->total_obtain = 0;
        
        // Student Marks + total
        int j;
        for (j = 0; j < MAX_SUBJ; j++) {
            do {
                cout << "Enter marks of subject " << j + 1 << " out of 100: ";
                cin >> temp->marks[j];
                if (temp->marks[j] >= 0 && temp->marks[j] <= 100  ) {
                    // Total marks
                    temp->total_obtain = temp->total_obtain + temp->marks[j];
                    // Percentage
                    temp->prcntge = ((static_cast<float>(temp->total_obtain) / 500.0) * 100);
                    // Grade
                    if (temp->prcntge >= 80) {
                        temp->grade = 'A';
                    } else if (temp->prcntge >= 70 && temp->prcntge < 80) {
                        temp->grade = 'B';
                    } else if (temp->prcntge >= 60 && temp->prcntge < 70) {
                        temp->grade = 'C';
                    } else if (temp->prcntge >= 50 && temp->prcntge < 60) {
                        temp->grade = 'D';
                    } else if (temp->grade >= 0 && temp->prcntge < 50) {
                        temp->grade = 'F';
                    }
                    break;
                }
                else {
                    cout << "Invalid Marks" << endl;
                }
            }while(true);
                    
        }
	}
	      else {
          temp = temp->next;
        }
	}	
}
				
//-------------------------------------------------------------------------
// Appending new Records

// Function to append a new student record at the end of the linked list
void  student :: appendRecord(student* head, int& numStudents) {
    if (numStudents >= capacity) {
        cout << "Cannot add more records. Maximum capacity reached." << endl;
        return;
    }

    student* newStudent = new student; // Create a new student node

    // Prompt for student details
    do {
            cout << "Enter registration ID between 4500-4800: ";
            cin >> newStudent->id;

            if (newStudent->id >= 4500 && newStudent->id <= 4800) {
                break; // Exit the loop
            } else {
                cout << "Invalid ID." << endl;
            }
        } while (true);

    cin.ignore(); // Ignore the newline character left in the input buffer
    cout << "Enter name of student: ";
    getline(cin, newStudent->name);

    newStudent->total_obtain = 0;
    for (int j = 0; j < MAX_SUBJ; j++) {
        do {
            cout << "Enter marks of subject " << j + 1 << " out of 100: ";
            cin >> newStudent->marks[j];
            if (newStudent->marks[j] >= 0 && newStudent->marks[j] <= 100) {
                newStudent->total_obtain += newStudent->marks[j];
                newStudent->prcntge = static_cast<double>(newStudent->total_obtain) / 500.0 * 100;
                if (newStudent->prcntge >= 80) {
                    newStudent->grade = 'A';
                } else if (newStudent->prcntge >= 70 && newStudent->prcntge < 80) {
                    newStudent->grade = 'B';
                } else if (newStudent->prcntge >= 60 && newStudent->prcntge < 70) {
                    newStudent->grade = 'C';
                } else if (newStudent->prcntge >= 50 && newStudent->prcntge < 60) {
                    newStudent->grade = 'D';
                } else {
                    newStudent->grade = 'F';
                }
                break;
            } else {
                cout << "Invalid Marks. Please enter marks between 0 and 100." << endl;
            }
        } while (true);
    }

    // Append the new student record to the end of the linked list
    student* temp = head;
    if (head == nullptr) {
        head = newStudent;
        // updating head if the linked list was previously empty because we will print the linked list using temp pointer
        temp = head;
    } 
	else {
        
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    numStudents++;
    cout << "Record added successfully." << endl;
// Clear Screen
                    system("cls");
            cout<<"\t\t\tBS computer Science Result Spring 2023"<<endl;
    cout<<endl;
    cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
    cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
  
  int serialNumber = 1;
   while(temp!=NULL){
   	temp->SerNo = serialNumber;
   	cout<<"\t"<<temp->SerNo<<"\t"<<temp->id<<"\t"<<temp->name<<"\t\t";
   	for(int j=0;j<MAX_SUBJ;j++){
   		cout<<temp->marks[j]<<"\t";
	   }
	cout<<temp->total_obtain<<"\t"<<temp->prcntge<<"%"<<"\t"<<temp->grade;
	cout<<endl;
	
	temp = temp->next;
	serialNumber++;

   }

   cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
}

//-----------------------------------------------------------------------------
// Deleting Record
  student* student :: deleteRecord(student*head, int &numStudents){
	student*temp = head;
    student*prev = head;
		int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       bool found = false;
       while(temp!=NULL){
       	  if(rollno==temp->id){
       	  	cout<<"Student found\n";
       	  	found = true;
       	  	if(temp==head){
       	  		temp = temp->next;
       	  		head = temp;
       	  		delete temp;
			 }
			 else if(temp!=head && temp->next!=NULL){
			 	prev->next = temp->next;
			 	delete temp;
			 }
			 else if(temp->next==NULL){
			 	delete temp;
			 }
					  	
}		
	    else{		
	      prev = temp;
		temp = temp->next;
        }
   
            numStudents--;
            // Clear Screen
                    system("cls");
            cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
    cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;
             for(int i=0;i<numStudents;i++){
   	cout<<"\t"<<temp->SerNo<<"\t"<<temp->id<<"\t"<<temp->name<<"\t\t";
   	for(int j=0;j<MAX_SUBJ;j++){
   		cout<<temp->marks[j]<<"\t";
	   }
	cout<<temp->total_obtain<<"\t"<<temp->prcntge<<"%"<<"\t"<<temp->grade;
	cout<<endl;
   }
            cout << "Record Deleted Successfully" << endl;
            break;
    
}
if(found!=true){
   	cout<<"Student Not found\n";
   }
   
    return head;	
}

//-----------------------------------------------------------------------------------------
// Show Data

void  student :: showData(student*head, int &numStudents){
	               // Clear Screen
                    system("cls");
                    cout<<"****Displaying Student Records****"<<endl;
       student*temp= head;
      if (temp==NULL) {
    cout << "No student records found." << endl;
        return;
    }
    else{
    	cout<<endl;
    cout <<"\tS.No\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\n";
    cout<<"    ----------------------------------------------------------------------------------------------------"<<endl;

// Print Serial Numbers
	// Print Serial Numbers
        int serialNumber = 1;
    while(temp!=NULL){
    	temp->SerNo = serialNumber;
   	cout<<"\t"<<temp->SerNo<<"\t"<<temp->id<<"\t"<<temp->name<<"\t\t";
   	for(int j=0;j<MAX_SUBJ;j++){
   		cout<<temp->marks[j]<<"\t";
	   }
	cout<<temp->total_obtain<<"\t"<<temp->prcntge<<"%"<<"\t"<<temp->grade;
	cout<<endl;
	temp = temp->next;
	serialNumber++;
   }
 }
}
//-----------------------------------------------
int main(){	
 // Creating object s of a student
 cout<<"Enter number of students in your class: ";
 int numStudents;
 cin>>numStudents;
 
   student*head = NULL;
    head =(student*) new student;
    
    student s[capacity];			     
                       cout<<"\t\t\tBS computer Science Result Spring 2023"<<endl;
    cout << "Getting Students Records" << endl;
           // Call the getData function on each student object
              for (int i = 0; i < numStudents; i++) {
                   s[i].getData(head,numStudents,i);
                }
	int choice;
    do {
        displayMenu();
        cout<<"Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Searching Record" << endl;
                         s[0].searchRecord(head,numStudents);
                break;
            case 2:
                cout << "Deleting Record" << endl;
                 head =   s[0].deleteRecord(head,numStudents);
                break;
            case 3:
                cout << "Updating Record" << endl;
                s[0].updateRecord(head, numStudents);
                break;
            case 4:
                cout << "Append New Record" << endl;
                     s[0].appendRecord(head,numStudents);
                break;
            case 5:                                   
                cout << "Display Result" << endl;  
				     s[0].showData(head,numStudents);      
                break;
            case 6:                                   
                cout << "Exiting Program" << endl;        
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    
    // Deallocate memory for each student
    
    return 0;
}

