#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(){} // no argument constructor
    node(int value) : data(value), next(nullptr) {}
};

class LinkList {
private:
    node* first;  // Points to the first link in the list

public:
    LinkList() : first(nullptr) {}

    // Function to add a link to the list
    void addLink(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = first;
        first = newNode;
    }
    
    // assignment overloaded operator
    
    LinkList &operator=(const LinkList &f){
    	if (first != f.first){
    		clear();
    		
    	node *temp = f.first;
    	  while(temp!=nullptr){
    		this->addLink(temp->data);
    		temp = temp->next;
		  }
	    }
	  return *this;	
	}

    // Function to display the links in the list
    void display() {
        node* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

   
    ~LinkList() {
        clear(); //  Destructor's alternative to delete all links in the list to avoid destroying data and links
    }
    
    void clear(){
    	node* current = first;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            cout << "Deleted link with value: " << temp->data <<endl;
            delete temp;
        }
	}
};

int main() {
    // Test the LinkList class
    LinkList list;
    list.addLink(3);
    list.addLink(7);
    list.addLink(1);

    cout << "Original list: ";
    list.display();
    cout << "new list: ";
    LinkList l1(list);
    l1.addLink(5);
    l1.addLink(84);
    l1.addLink(56);
    l1.display();
    cout<<endl;
     l1 = list;
    l1.display();
    
    return 0;
}
