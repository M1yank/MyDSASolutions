//{ Driver Code Starts
//naive complexity is O(n)
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

Node *deletebegin(Node *head){
	if(head==NULL) return NULL;
	
	if(head->next==NULL){
		delete head;
		return NULL;
	}
	
	head->data=head->next->data;	//copy 2nd element data to head
	Node *temp=head->next;			//make temp node with head->next pointer
	head->next=head->next->next;	//store the 2nd element address to 3rd element
	delete temp;					//delete 2nd element
	return head;				
}



Node *deletekth(Node *head, int k){
	if(head==NULL) return NULL;
	if(k==1){
		return deletebegin(head);
	}
	
	Node *curr=head;
	for(int i=0; i<k-2; i++){
		curr=curr->next;
	}
	Node *temp=curr->next;
	curr->next=temp->next;
	delete temp;
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
	
	//Delete at kth element
	head=deletekth(head, 2);	//k<length of linked list for input, can be modified otherwise
	cout<<"\nAfter Deleting :\n";
    printList(head);
	return 0;
}
