//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int d){
    	data=d;
    	next=NULL;
	}
};


void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node *reverse(Node *head){
	Node *curr=head;
	Node *prev=NULL;
	while(curr!=NULL){
		Node *next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}


int main()
{
	Node *head;
	Node *n1 = new Node(10);
    Node *n2 = new Node(20);
	Node *n3 = new Node(30);
	Node *n4 = new Node(40);
	Node *n5 = new Node(50);
	head=n1;
	
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=NULL;
    printList(head);
    
    //reverse linked list
    head=reverse(head);
    cout<< "\nReversed: \n";
    printList(head);
	return 0;
}
