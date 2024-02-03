#include<iostream>
using namespace std;

void compareString(char* s1, char* s2){
	// Calculating length of s1
	int s1_length = 0;
	while(s1[s1_length]!='\0'){
		s1_length++;
	}
	// Calculating length of s2
	int s2_length = 0;
	while(s2[s2_length]!='\0'){
		s2_length++;
	}
	if (s1_length > s2_length){
	cout<<"String 1 is greater than String 2....";
	}
	else if(s1_length < s2_length)
	cout<<"String 2 is greater than String 1....";
	else if (s1_length == s2_length)
	{
		for(int i=0;s1[i]!='\0';i++){
			if(s1[i]>s2[i]){
				cout<<"String 1 is greate than string 2";
				break;
			}	
			cout<<"String 2 is greater than String 1";
			   break;
		}
			
		
	}
}

int main(){
	 char input1[20], input2[20];
    cout << "Enter string 1: ";
    cin.getline(input1, sizeof(input1));

    cout << "Enter string 2: ";
    cin.getline(input2, sizeof(input2));
    
    compareString(input1,input2);
    
}