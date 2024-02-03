#include <iostream>

using namespace std; 

int searchInString(char* s1,char* s2) {
	// Calculating length of s2
	int s2_length = 0;
	while(s2[s2_length]!='\0'){
		s2_length++;
	}
//	cout<<s2_length<<endl;
    for(int i=0;s1[i]!='\0';i++){
        	if(*s2==s1[i]){
        		const char*temp = s2;
        		const char* s1ptr = &s1[i]; // Pointer to the current position in s1
        	     while(*temp != '\0' && *temp == *s1ptr){
        		temp++;
        		s1ptr++;
			   }
			   // Comparing length of substring and matched portion of actuall string
			   if(s1ptr - &s1[i] == s2_length){
			   	return i;	
			   }			       
		}
	}
    return -1;
}


int main() {
    char input1[20],input2[20];

    cout << "Enter string: ";
    cin.getline(input1, sizeof(input1));
    cout << "Enter substring: ";
    cin.getline(input2, sizeof(input2));

  int index =  searchInString(input1,input2);
  if(index!=-1)
    cout<<"The substring is found at index: "<<index;
  else if(index==-1)
    cout<<"Substring not found";
    return 0;
}
