#include<iostream>
#include<string>
using namespace std;

class Mystring{
	private:
	    string s1;
	public:
		// Constructor
		Mystring(string s1=""):s1(s1){}
		// Member Functions
	    void setter();
	    void getter();
	    int getLength();
	    Mystring operator+(Mystring SS);
	    Mystring operator-(Mystring SS);
		int operator>(Mystring SS);
		int getLength(Mystring SS);  
};

void Mystring :: setter(){
    cout << "Enter string   ";
    getline(cin, s1);
}


void Mystring :: getter(){
	cout<<s1;
	cout<<endl;
}

int Mystring::getLength() {
	int count = 0;
	while(s1[count]!='\0'){
		count++;
	}
	return count;
}


Mystring Mystring :: operator+(Mystring SS){
	Mystring result;
	result.s1= s1+SS.s1;
	return result;
}

Mystring  Mystring :: operator-(Mystring SS){
	Mystring result;
size_t found = s1.find(SS.s1);

    if (found == 0) {
        cout << "Substring found at the beginning of the string." <<endl;
    } else if (found !=string::npos) {
        cout << "Substring found at position " << found << endl;
    } else {
        cout << "Substring not found in the string." << endl;
    }
    if (found !=string::npos) {
    	// Erase the found substring
        result.s1=s1.erase(found, SS.s1.length());
        cout<<"String after removing substring: "<<result.s1<<endl;
    }
    return result;
}


int Mystring :: operator>(Mystring SS){
	    Mystring result;
        
    // Use the compare function to compare the strings
    int comparisonResult = s1.compare(SS.s1);
       return comparisonResult;
}

int main(){
	Mystring s1,s2,s3;
	
 int choice;
     do{
        cout << "Main Menu" << endl;
        cout << "1. Concatinate Strings " << endl;
        cout << "2. Compare strings " << endl;
        cout << "3. Search and Delete substring " << endl;
        cout << "4. Length of a string " << endl;
        cout << "5. Exit " << endl;
        cout << "------------***------------ ";
        cout << "Enter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
            	cin.ignore();
                cout << "Concatinate strings" << endl;
                s1.setter();
	            s2.setter();
             	s3 = s1+s2;
	            s3.getter();
                break;
            case 2:
            		cin.ignore();
                cout << "Compare strings" << endl;
                s1.setter();
	            s2.setter();
                int comparisonResult;
				comparisonResult = s1>s2;
                if (comparisonResult > 0) {
                cout<<"S1 is greater than S2"<<endl;
                } else if (comparisonResult < 0) {
                cout<<"S2 is greater than S1"<<endl;
                } else {
                // If the strings are equal
                cout<< "Equal"; 
	            }	
                break;
            case 3:
            		cin.ignore();
                cout << " Search and Delete Substring" << endl;
            s1.setter();
	        s2.setter();
	        s3 = s1-s2;
	        s3.getter();
                break;
            case 4:
            		cin.ignore();
                cout << "Length of a string" << endl;
                s1.setter();
                int length;
				 length = s1.getLength();
                cout << "Length: " << length  << endl;
                 break;
            case 5:
            	cout<<"Exiting Program";
            	return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }while(true);
}