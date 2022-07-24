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

Node *deleteend(Node *head){
	if(head==NULL) return NULL;	//if linked list is empty
	if(head->next==NULL) {		//check whether linked list contains only 1 element, if yes just delete head and return null
		delete head;
		return NULL;	
	}
	
	Node *curr=head;
	while(curr->next->next!=NULL){	//check whether linked list contains more than 2 elements or not
		curr=curr->next;
	}
    delete curr->next;
    curr->next=NULL;
    return head;
	
}

Node *insertpos(Node *head, int pos, int x){
	Node *temp= new Node;
	temp->data=x;
	if(pos==1){
		temp->next=head;
		return temp;
	}
	
	Node *curr=head;
	for(int i=1; i<pos-1 && curr!=NULL; i++){
		curr=curr->next;
	}
	
	if(curr==NULL) return head;
	
	temp->next=curr->next;
	curr->next=temp;
	return head;
	
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
    
    //insert node at given pos:
    head=insertpos(head, 2, 20);
    //inserted at pos 2 ( first element is indexed as 1);
    
    cout<< "\nAfter insertion: \n";
    printList(head);
	return 0;
}
