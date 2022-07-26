//{ Driver Code Starts
//need to set the last node next to head, so complexity is O(n)
//to do it in O(1), we can maintain tail pointer
//or second method is to: 	(i) insert new node after head
//							(ii) swap the data of head and head->next.  DONE 
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

Node *insertbegin(Node *head, int x){
	Node *temp=new Node(x);
	if(head==NULL){
		temp->next=temp;
		return temp;
	}
	
	temp->next = head->next;
	head->next = temp;
	int t = head->data;
	head->data = temp->data;
	temp->data=t;
	return head;
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
	
	//Insert at begin
	head=insertbegin(head, 100);
	cout<<"\nAfter Inserting at begin:\n";
    printList(head);
	return 0;
}
