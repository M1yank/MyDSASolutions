//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
    int data;
    struct Node *prev;
    struct Node *next;
    Node(int d){
    	data=d;
    	prev=NULL;
    	next=NULL;
	}
};

void printList(Node* node){
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node *insertbegin(Node *head, int x){
	Node *temp=new Node(x);
	temp->next=head;
	if(head!=NULL)
		head->prev=temp;
	return temp;
}

Node *insertend(Node *head, int x){
	Node *temp=new Node(x);
	if(head==NULL) return temp;
	
	Node *curr=head;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=temp;
	temp->prev=curr;
	return head;
}


Node *reverse(Node *head){
	if(head==NULL || head->next==NULL) return head;
	Node *temp=NULL, *curr=head;
	while(curr!=NULL){
		//swap code
		temp=curr->prev;
		curr->prev=curr->next;
		curr->next=temp;
		
		curr=curr->prev;	//cuz we have swapped prev and next
	}
	return temp->prev;		//return head
}


int main()
{
	Node *head=new Node(10);
	Node *n1 = new Node(20);
    Node *n2 = new Node(30);
	Node *n3 = new Node(40);
	
	head->next=n1;
	
	n1->next=n2;
	n1->prev=head;
	
	n2->next=n3;
	n2->prev=n1;
	
	n3->prev=n2;
	
	//printList(head);
    
    //Insert at begin:
    head=insertbegin(head, 90);
    //cout<<"\nAfter inserting at begin: \n";
    //printList(head);
    //insertted at begin
    
    //Insert at end:
    head=insertend(head, 100);
    //cout<<"\nAfter inserting at end: \n";
    cout<<"Before Reversing: \n";
	printList(head);
    //insertted at end
    
    
    //Reverse the list
    cout<<"\nAfter Reversing: \n";
    head=reverse(head);
    printList(head);
    //reversed
    
	return 0;
}
