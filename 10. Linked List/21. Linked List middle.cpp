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


void printmiddle(Node *head){
	if(head==NULL) return;
	Node *slow=head;	//slow moves 1 at a time
	Node *fast=head;	//fast moves 2 at a time
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<slow->data;
}


int main()
{
	Node *head;
	Node *n1 = new Node(10);
    Node *n2 = new Node(20);
	Node *n3 = new Node(30);
	Node *n4 = new Node(40);
	
	head=n1;
	
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=NULL;
    printList(head);
    
    //print middle, eg, 1 2 3 4 5 -> 3 ;;;;  1 2 3 4 -> 3
    cout<< "\nMiddle Element: \n";
    printmiddle(head);
	return 0;
}
