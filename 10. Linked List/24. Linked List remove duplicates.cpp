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

Node *removeduplicates(Node *head){
	Node *curr=head;
	while(curr!=NULL && curr->next!=NULL){		//curr->next!=NULL to avoid segmentation
		if(curr->data==curr->next->data){
			Node *temp=curr->next;
			curr->next=curr->next->next;
			delete temp;
		}
		else
			curr=curr->next;
	}
	return head;	
}


int main()
{
	Node *head;
	Node *n1 = new Node(10);
    Node *n2 = new Node(20);
	Node *n3 = new Node(20);
	Node *n4 = new Node(40);
	Node *n5 = new Node(40);
	head=n1;
	
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=NULL;
    printList(head);
    
    //remove duplicates
    head=removeduplicates(head);
    cout<< "\nAfter Removing Duplicates: \n";
    printList(head);
	return 0;
}
