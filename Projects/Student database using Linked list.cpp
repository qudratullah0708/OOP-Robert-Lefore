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
	struct student*next;
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
void getData(struct student *head, int &numStudents) {
	struct student*temp = head;
    for (int i = 0; i < numStudents; i++) {
        temp->SerNo = i + 1;
    }
    
    for (int i = 0; i < numStudents; i++) {
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
        for (j = 0; j < 5; j++) {
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
}


//Searching Record
void searchRecord(struct student*head,int &numStudents){
int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       bool found = false;
       struct student*temp = head;
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
void updateData(struct student *head, int &numStudents) {
	
	int rollno;
       cout<<"Enter Roll no of student: ";
       cin>>rollno;
       bool found = false;
       struct student*temp = head;
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
        for (j = 0; j < 5; j++) {
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
void appendRecord(struct student* head, int& numStudents) {
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
    for (int j = 0; j < 5; j++) {
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
   	for(int j=0;j<5;j++){
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
struct student* deleteRecord(struct student*head, int &numStudents){
	struct student*temp = head;
	struct student*prev = head;
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
   	for(int j=0;j<5;j++){
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

void showData(struct student*head, int &numStudents){
	               // Clear Screen
                    system("cls");
                    cout<<"****Displaying Student Records****"<<endl;
     struct student*temp= head;
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
   	for(int j=0;j<5;j++){
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
 
  struct student*head = NULL;
    head =(struct student*) new student;
    
	/////////////////////////////////////////////////////////////     
        cout<<"\t\t\tBS computer Science Result Spring 2023"<<endl;
                       
    cout << "Getting Students Records" << endl;
           getData(head,numStudents);
           cin.ignore();
	int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Searching Record" << endl;
                         searchRecord(head,numStudents);
                break;
            case 2:
                cout << "Deleting Record" << endl;
                 head =   deleteRecord(head,numStudents);
                break;
            case 3:
                cout << "Updating Record" << endl;
                updateData(head, numStudents);
                break;
            case 4:
                cout << "Append New Record" << endl;
                     appendRecord(head,numStudents);
                break;
            case 5:                                   
                cout << "Display Result" << endl;  
				     showData(head,numStudents);      
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