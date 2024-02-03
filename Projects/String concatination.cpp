#include <iostream>

using namespace std; 

void ConcatString(char* s1, char* s2, char* result) {
    // Copy characters from s1 to result
    while (*s1 != '\0') {
        *result = *s1;
        s1++;
        result++;
    }
    // Adding space before concatenating the second string
    *result = ' ';
    result++;
    // Copy characters from s2 to result
    while (*s2 != '\0') {
        *result = *s2;
        s2++;
        result++;
    }
    *result = '\0'; // Null termination
}

void print(char *output){
	cout<<output;
}

int main() {
    char input1[20], input2[20], output[40];

    cout << "Enter string 1: ";
    cin.getline(input1, sizeof(input1));

    cout << "Enter string 2: ";
    cin.getline(input2, sizeof(input2));

    ConcatString(input1, input2, output);
    print(output);
   // cout << "Concatenated string: " << output << endl;

    return 0;
}
