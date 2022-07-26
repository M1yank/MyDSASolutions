//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
    int data;
    struct Node *next;
    Node(int d){
    	data=d;
    	next=NULL;
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
	n1->next=n2;
	n2->next=n3;
	n3->next=head;
	printList(head);
    
	return 0;
}
