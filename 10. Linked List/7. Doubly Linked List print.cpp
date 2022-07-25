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


void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
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
	
	printList(head);
    
	return 0;
}
