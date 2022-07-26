//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node *deletehead(Node *head){
	if(head==NULL) return NULL;
	else{
		Node *temp=head->next;
    	delete head;
    	return temp;
	}
}


int main()
{
	Node *head;
	Node *n1 = new Node;
    Node *n2 = new Node;
	Node *n3 = new Node;
	
	head=n1;
	n1->data=1;
	n2->data=2;
	n3->data=3;
	
	n1->next=n2;
	n2->next=n3;
	n3->next=NULL;
	
    printList(head);
    
    //delete head node:
    head=deletehead(head);
    //deleted;
    
    cout<< "\nAfter deletion: \n";
    printList(head);
	return 0;
}
