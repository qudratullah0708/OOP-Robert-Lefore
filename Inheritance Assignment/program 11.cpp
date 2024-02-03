#include <iostream>
using namespace std;
class Stack {
protected:
    static const int MAX = 8;

    int st[MAX];

    int top;

public:
    Stack() : st(), top(-1) {}

    void push(int var) { st[++top] = var; }

    int pop() { return st[top--]; }
};

class Stack2 : public Stack {
public:
    void push(int var) {
        if (top >= MAX - 1) {
            cout << "Stack is full!" << endl;
            exit(1);
        }

        Stack::push(var);
    }

    int pop() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            exit(1);
        }

        return Stack::pop();
    }
};

struct Mypair {
    int x;
    int y;
}; 
        
class pairStack : public Stack2{
  public:
  	void push(Mypair var){																																								
	Stack2 :: push(var.x);
	Stack2 :: push(var.y);
    }
  	Mypair  pop(){
	Mypair var;	  
 var.y= Stack2 ::pop();
 var.x=Stack2::pop();
 return var;
 }
 
};

int main()
{
Mypair mypair = {11, 22};	
pairStack s1;
s1.push(mypair); // push the pair onto the stack
s1.push(mypair);
Mypair res = s1.pop(); // pop a pair from the stack
cout << "x: " << res.x << ", y: " << res.y <<endl;
return 0;
}
