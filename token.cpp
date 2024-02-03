#include <iostream>
#include <string>
#include <cstdlib>

                 //  *****      #Submitted by:  Qudrat Ullah     ******
                //       #Reg No :       4741/BSCS/F22/B
               //        #Title :      String Parsing
using namespace std;

const int MAX = 100; // Adjust as needed

class Stack {
private:
    char st[MAX]; // stack: array of chars
    int top;       // number of top of stack

public:
    Stack() { top = -1; } // constructor

    void push(char var) { st[++top] = var; } // put char on stack

    char pop() { return st[top--]; } // take char off stack

    int getTop() { return top; } // get top of stack
    
    char topElement(){ return st[top];}
};

class StackValue {
private:
    float st[MAX]; // stack: array of floats
    int top;       // number of top of stack

public:
    StackValue() { top = -1; } // constructor

    void push(float var) { st[++top] = var; } // put float on stack

    float pop() { return st[top--]; } // take float off stack

    int getTop() { return top; } // get top of stack
};

class Expression {
private:
    Stack s;          // stack for operators
    StackValue s1;    // stack for numeric values
    string pStr;      // input string

public:
    Expression(const string& str) : pStr(str) {}

    void parse(); // parse the input string

    float solve();  // evaluate the expression
};

void Expression::parse() {
    char ch;
    float floatValue;
    char lastop;
    float lastval;

    for (int j = 0; j < pStr.length(); j++) {
        ch = pStr[j];

        if (isdigit(ch)) {
            // Check for multi-digit numbers
            string numStr;
            while (j < pStr.length() && (isdigit(pStr[j]) || pStr[j] == '.')) {
                numStr += pStr[j];
                j++;
            }

            floatValue = stof(numStr);
            s1.push(floatValue);
            j--; // Adjust index to account for the last processed character
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (s.getTop() != -1 && (s.topElement() == '*' || s.topElement() == '/')) {
                lastop = s.pop();
                lastval = s1.pop();
                switch (lastop) {
                    case '*':
                        s1.push(s1.pop() * lastval);
                        break;
                    case '/':
                        s1.push(s1.pop() / lastval);
                        break;
                    case '-':
                        s1.push(s1.pop() - lastval);
                        break;
                    case '+':
                        s1.push(s1.pop() + lastval);
                        break;
                    default:
                        cout << "\nUnknown operator";
                        exit(1);
                }
            }
            s.push(ch);
        } /*else if (ch == '*' || ch == '/') {
            s.push(ch);
        }*/
    }
}


float Expression::solve() {
    // Perform final evaluation based on remaining operators
    while (s.getTop() != -1 && s1.getTop() > 0) {
        char lastop = s.pop();
        float lastval = s1.pop();
        switch (lastop) {
            case '+':
                s1.push(s1.pop() + lastval);
                break;
            case '-':
                s1.push(s1.pop() - lastval);
                break;
            case '*':
                s1.push(s1.pop() * lastval);
                break;
            case '/':
                s1.push(s1.pop() / lastval);
                break;
            default:
                cout << "\nUnknown operator";
                exit(1);
        }
    }

    return s1.pop();
}

int main() {
    char ans;
    string input;

    cout << "Enter an arithmetic expression of the form 2+3*4/3-2.\n"
         << "Numbers can have more than one digit.\n"
         << "Allow whitespace between numbers and operators.\n";
		// << "***********Challenge My Limits*********.\n";

    do {
        cout << "Enter expression: ";
        getline(cin, input);

        Expression* expr = new Expression(input);
        expr->parse();
        cout << "The numerical value is: " << expr->solve() << endl;

        delete expr;

        cout << "Do another (Enter y or n)? ";
        cin >> ans;
        cin.ignore(); // Consume the newline character
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
