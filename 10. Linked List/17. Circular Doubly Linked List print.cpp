//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
    int data;
    Node *next;
    Node *prev;
    Node(int d){
    	data=d;
    	next=NULL;
    	prev=NULL;
	}
};


void printList(Node* head)
{
    if(head==NULL) return;
	Node *temp=head;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;	
	}while(temp!=head);
}



int main()
{
	Node *head=new Node(10);
	Node *n1 = new Node(20);
    Node *n2 = new Node(30);
	Node *n3 = new Node(40);
	
	head->next=n1;
	head->prev=n3;
	
	n1->next=n2;
	n1->prev=head;
	
	
	n2->next=n3;
	n2->prev=n1;
	
	n3->next=head;
	n3->prev=n2;
	
	printList(head);
    
	return 0;
}
