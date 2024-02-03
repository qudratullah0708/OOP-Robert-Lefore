#include<iostream>
using namespace std;

#define MAX 20

class myStack{
	protected:
		int top;
		int l[MAX];
	public:
		myStack():top(-1),l(){}
	   void push(int d);
	   int pop();
};

void  myStack :: push(int d){
	   	if(top==MAX-1){
	   		cout<<" Stack overflow "<<endl;
		   }
		else{
			top++;
			l[top]=d;
		}
    }
    
int  myStack :: pop(){
	   	if(top==-1){
	   		cout<<" Stack underflow "<<endl;
		   }
		else{
			int temp = l[top];
		    top--;
		    return temp;
		}
    }
class nMyStack : virtual public myStack{
	public:
		int peek(int &x);
};

int  nMyStack :: peek(int &x){
			if(top==-1){
	   		cout<<" Stack underflow "<<endl;
	        }    
	        else{
	        	x = l[top-1];
	        	return l[top];
			}
			
}

struct point{
	int x;
	int y;
	int z;
};


int main(){
	int a,b;
  nMyStack s1;
  s1.push(100);
  s1.push(50);
  a=s1.peek(b);
  cout<<"The top two values are "<<a<<" and "<<b<<endl;	
  
  struct point p1,p2,p3;
  p1.x = 60;
  p1.y = 70;
  p1.z = 80;
  s1.push(p1.x);
  s1.push(p1.y);
  s1.push(p1.z);
  
  p2.x = 100;
  s1.push(p2.x);
  p2.y = 200 ;
  s1.push(p2.y);
  p2.z = 300;
  s1.push(p2.z);
   
  p3.z = s1.pop();
  p3.y = s1.pop();
  p3.x = s1.pop();
  cout<<"The points are x="<<p1.x<<" y= "<<p1.y<<" z= "<<p1.z<<endl;
  
  
  
  
}