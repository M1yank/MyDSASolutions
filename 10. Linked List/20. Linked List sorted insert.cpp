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


Node *insertsorted(Node *head, int x){
	Node *temp= new Node(x);
	if(head==NULL){
		return temp;
	}
	
	if(x<head->data){
		temp->next=head;
		return temp;
	}
	
	
	Node *curr=head;
	while(curr->next!=NULL &&curr->next->data<x){
		curr=curr->next;
	}

	temp->next=curr->next;
	curr->next=temp;
	return head;
	
}


int main()
{
	Node *head;
	Node *n1 = new Node(10);
    Node *n2 = new Node(20);
	Node *n3 = new Node(30);
	
	head=n1;
	
	n1->next=n2;
	n2->next=n3;
	n3->next=NULL;
	
    printList(head);
    
    //insert node at sorted pos:
    head=insertsorted(head, 5);
    head=insertsorted(head, 20);
    head=insertsorted(head, 25);
    
    cout<< "\nAfter insertion: \n";
    printList(head);
	return 0;
}
