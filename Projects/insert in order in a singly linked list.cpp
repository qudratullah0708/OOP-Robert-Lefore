#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *link;
}


void insert_at_last(struct node *head, int a){
	struct node *ptr, *temp;     
	ptr = head;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->link = NULL;
	while(ptr->link!=NULL){
		ptr = ptr->link;
	}
	ptr = ptr->temp;
}




struct node* insert_Order(struct node*head,int a){
	struct node *ptr, *inode;     
	ptr = head;
	inode = (struct node*)malloc(sizeof(struct node));
	inode->data = a;
	inode->link = NULL;
	if(inode->data <= ptr->data){
	    inode->link = head;
	    head = inode;
	    return head;
	}
	else{
		while(inode->data <= ptr->data){
	    inode->link = head;
	    head = inode;
	    return head;
	}
	if(cur!=NULL)
	// Middle Insertion
	else 
	//insert at last
	
}


int main(){
	
	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;
    
    struct node *current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;
    insert_at_last(head,2);
	insert_Order(head,4);
	
}