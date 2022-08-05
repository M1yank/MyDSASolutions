//https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
//{ Driver Code Starts
/*
Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
*/


#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends

//Function to merge two sorted linked list.
Node* sortedMerge(Node* a, Node* b)  
{  
    if(a==NULL) return b;
    if(b==NULL) return a;
    Node *head= NULL, *tail=NULL;
    
    if(a->data<=b->data){
        head=tail=a;
        a=a->next;          //whichever smaller move ahead
    }
    else{
        head=tail=b;
        b=b->next;
    }
    
    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            tail->next=a;
            tail=a;
            a=a->next;
        }
        else{
            tail->next=b;
            tail=b;
            b=b->next;
        }
    }
    if(a==NULL) tail->next=b;
    else tail->next=a;
    return head;
    
}  