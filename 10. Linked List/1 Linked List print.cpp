//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


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
	
    Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
		}
    
	return 0;
}
