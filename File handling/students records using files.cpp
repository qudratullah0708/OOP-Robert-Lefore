#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int capacity = 70;

#define MAX_SUBJ 5

class airTime {
private:
    unsigned int hr, min, sec;

public:
    airTime(int hh = 0, int mm = 0, int ss = 0) : hr(hh), min(mm), sec(ss) {}

    void timeSetter();
    void displaytime();
    bool operator>(const airTime &TT);

    unsigned int getHours() const { return hr; }
    unsigned int getMinutes() const { return min; }
    unsigned int getSeconds() const { return sec; }

    void setTime(int hh, int mm, int ss) {
        hr = hh;
        min = mm;
        sec = ss;
    }
};

void airTime::timeSetter() {
    do {
        cout << "Enter hour: ";
        cin >> hr;
        if (hr >= 0 && hr < 24) {
            break;
        } else {
            cout << "invalid hour" << endl;
        }
    } while (true);

    do {
        cout << "minutes: ";
        cin >> min;
        if (min >= 0 && min < 60) {
            break;
        } else {
            cout << "invalid minutes" << endl;
        }
    } while (true);

    do {
        cout << "seconds: ";
        cin >> sec;
        if (sec >= 0 && sec < 60) {
            break;
        } else {
            cout << "invalid seconds" << endl;
        }
    } while (true);
}

void airTime::displaytime() {
    cout << hr << ":" << min << ":" << sec << endl;
}

bool airTime::operator>(const airTime &TT) {
    if (hr > TT.hr)
        return true;
    else if ((hr == TT.hr) && (min > TT.min))
        return true;
    else if ((hr == TT.hr) && (min == TT.min) && (sec > TT.sec))
        return true;
    else
        return false;
}

class student {
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
    int getID(int newId) { return id; }

    void writeToFile(ofstream &outFile);
    void readFromFile(ifstream &inFile);

    void setIntime() {
        cout << "Enter intime of student in 24 hour format " << endl;
        intime.timeSetter();
    }

    void setOuttime() {
        cout << "Enter outtime of student int 24 hour format  " << endl;
        outtime.timeSetter();
    }

    void showIntime() { intime.displaytime(); }

    void showOuttime() { outtime.displaytime(); }

    bool isOuttimeGreaterThanIntime() { return outtime > intime; }
};

void student::setter() {
    do {
        cout << "Enter registration ID between 4500-4800: ";
        cin >> id;

        if (id >= 4500 && id <= 4800) {
            break;
        } else {
            cout << "Invalid ID. " << endl;
        }
    } while (true);

    cout << endl;
    cin.ignore();

    cout << "Enter name of student: ";
    getline(cin, name);
    cout << endl;

    total_obtain = 0;

    for (int j = 0; j < MAX_SUBJ; j++) {
        do {
            cout << "Enter marks of subject " << j + 1 << " out of 100: ";
            cin >> marks[j];
            if (marks[j] >= 0 && marks[j] <= 100) {
                total_obtain = total_obtain + marks[j];
                prcntge = ((static_cast<float>(total_obtain) / 500.0) * 100);

                if (prcntge >= 80) {
                    grade = 'A';
                } else if (prcntge >= 70 && prcntge < 80) {
                    grade = 'B';
                } else if (prcntge >= 60 && prcntge < 70) {
                    grade = 'C';
                } else if (prcntge >= 50 && prcntge < 60) {
                    grade = 'D';
                } else if (grade >= 0 && prcntge < 50) {
                    grade = 'F';
                }
                break;
            } else {
                cout << "Invalid Marks" << endl;
            }
        } while (true);
    }

    setIntime();
    setOuttime();

    while (!isOuttimeGreaterThanIntime()) {
        cout << "Outtime must be greater than intime " << endl;
        setOuttime();
    }
}

void student::getter() {
    cout << "\t" << id << "\t" << name << "\t\t";
    for (int j = 0; j < MAX_SUBJ; j++) {
        cout << marks[j] << "\t";
    }
    cout << total_obtain << "\t" << prcntge << "%" << "\t" << grade << "\t";
    showIntime();
    showOuttime();
    cout << endl;
}

void student::searchRecord(int rollno) {
    system("cls");
    bool found = false;
    if (rollno == id) {
        cout << "Student found\n";
        found = true;
        cout << "\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\tInTime\tOutTime\n";
        cout << "        ----------------------------------------------------------------------------------------------------" << endl;
        cout << "\t" << id << "\t" << name << "\t\t";
        for (int j = 0; j < 5; j++) {
            cout << marks[j] << "\t";
        }
        cout << total_obtain << "\t" << prcntge << "%" << "\t" << grade << "\t";
        showIntime();
        showOuttime();
        cout << endl;
        cout << "        ----------------------------------------------------------------------------------------------------" << endl;
    }
    if (found == false) {
        cout << "Student Not found\n";
    }
}

bool student::compareId(int rollno) {
    if (rollno == id) {
        cout << "Student found\n";
        return true;
    }
    return false;
}

void student::deleteRecord() {
    id = 0;
    for (int k = 0; k < MAX_SUBJ; k++) {
        marks[k] = 0;
    }

    name = "None";
    prcntge = 0.0;
    total_obtain = 0;
    grade = '\0';
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "0. Get Student Records from scrach" << endl;
    cout << "1. Search Record" << endl;
    cout << "2. Delete Record" << endl;
    cout << "3. Update Record" << endl;
    cout << "4. Append Record" << endl;
    cout << "5. Display Result Card" << endl;
    cout << "6. Writing on file" << endl;
    cout << "7. Reading from file" << endl;
    cout << "8. Quit" << endl;
}

void student::writeToFile(ofstream &outFile) {

    outFile << id << " " << name << " ";
    for (int j = 0; j < MAX_SUBJ; j++) {
        outFile << marks[j] << " ";
    }
    outFile << total_obtain << " " << prcntge << " " << grade << " ";

    outFile << intime.getHours() << " " << intime.getMinutes() << " " << intime.getSeconds() << " ";
    outFile << outtime.getHours() << " " << outtime.getMinutes() << " " << outtime.getSeconds() << endl;
}

void student::readFromFile(ifstream &inFile) {
 
	//extraction operator consider white space characters as data seperators and don't read it so we use get() method
	char ch;
	ch = inFile.get();
	while(!inFile.eof()){
	//cout<<ch;
	ch = inFile.get();
	}
}

void writeStudentsToFile(student s[], int numStudents) {
    ofstream outFile;
    outFile.open("student_records.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        s[i].writeToFile(outFile);
    }

    outFile.close();
}

void readStudentsFromFile(student s[], int numStudents) {
    ifstream inFile;
    inFile.open("student_records.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        s[i].readFromFile(inFile);
       s[i].getter();
    }

    inFile.close();
}

int main() {
    cout << "What's your class strength (Max up to) " << capacity << ": ";
    int numStudents;
    cin >> numStudents;
    if (numStudents <= 0 && numStudents > capacity) {
        cout << "No of Students must be between 1 and " << capacity << ": ";
        cin >> numStudents;
    }

    student s[capacity];
    cout << "\t\t\tBS computer Science Result Spring 2023" << endl;
    

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        	case 0:
        		cout << "Getting Students Records" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the details of student No." << i + 1 << endl;
        s[i].setter();
    }
        	break;
            case 1:
                cout << "Searching Record" << endl;
                cout << "Enter Roll No. ";
                int rollno;
                cin >> rollno;
                for (int i = 0; i < numStudents; i++) {
                    s[i].searchRecord(rollno);
                    break;
                }
                for (int i = 0; i < numStudents; i++)
                    if (s[i].compareId(rollno) != true) {
                        cout << "Record not found" << endl;
                    }
                break;
            case 2:
                cout << "Deleting Record" << endl;
                int roll;
                cout << "Enter Roll no of student: ";
                cin >> roll;
                for (int i = 0; i < numStudents; i++) {
                    if (s[i].compareId(roll) == true) {
                        s[i].deleteRecord();
                        cout << "Record Deleted Successfully" << endl;
                        break;
                    }
                }
                break;
            case 3:
                cout << "Updating Record" << endl;
                cout << "Enter Roll No. ";
                cin >> rollno;
                for (int i = 0; i < numStudents; i++) {
                    if (s[i].compareId(rollno) == true) {
                        s[i].setter();
                        cout << "Record updated Successfully";
                        break;
                    }
                }

                break;
            case 4:
                cout << "Append New Record" << endl;
                if (numStudents >= capacity) {
                    cout << "Cannot add more records. Maximum capacity reached." << endl;
                } else {
                    s[numStudents].setter();
                    numStudents++;
                    cout << "Record added successfully." << endl;
                }
                break;
            case 5:
                cout << "Display Result" << endl;
                system("cls");

                cout << endl;
                cout << "\t\t\t\tResult Card\t\t\t\t" << endl
                     << endl;
                cout << "\tS.id\tName\t\ts1\ts2\ts3\ts4\ts5\tT.Marks\t%age\tGrade\tInTime\tOutTime\n";
                cout << "        ----------------------------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < numStudents; i++) {
                    s[i].getter();
                }
                cout << "        ----------------------------------------------------------------------------------------------------" << endl;
                break;

            case 6:
                cout << "Writing to file" << endl;
                writeStudentsToFile(s, numStudents);
                break;

            case 7:
                cout << "Reading from file" << endl;
                readStudentsFromFile(s, numStudents);
                break;

            case 8:
                cout << "Exiting Program" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
