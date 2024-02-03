#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
};


node* insert_at_first(node*head,int a){
      node*temp = new node;
      temp->data = a;
      temp->next = head;
      head = temp;
      return head;
}

node* insert_at_last(node*head,int a){
	node*temp = new node;
	node*ptr = head;
	
      while(ptr->next!=NULL){
      	ptr = ptr->next;
	  }
	   temp->data = a;
      temp->next = NULL;
      ptr->next = temp;
      return head;      
}

node* insert_in_middle(node*head, int a){
	node*temp = new node;
	node*ptr = head;
	int pos = 2;
	while(pos!=1){
		ptr = ptr->next;
		pos--;
	}
	temp->data = a;
	temp->next = ptr->next;
	ptr->next = temp;
	return head;
}
int main(){
	node* head = new node;
	head->data = 45;
	head->next = NULL;
    head = insert_at_first(head,47);
    head = insert_at_last(head,56);
    head = insert_in_middle(head,67);
    node*ptr = head;
    while(ptr!=NULL){
    	cout<<ptr->data<<" ";
    	ptr = ptr->next;
	}
}