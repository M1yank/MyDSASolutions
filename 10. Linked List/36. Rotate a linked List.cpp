/*
https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

Given a singly linked list of size N. The task is to left-shift 
the linked list by k nodes, where k is a given positive integer 
smaller than or equal to length of the linked list.
Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        //STEPS: 
        //  1) just move curr pointer until k-1 and mark it as end;
        //  2) mark next node as start and put end->next=NULL
        //  3) now just iterate curr until we find null and point it to head
        //  4) return start
        
        
        Node *curr=head;
        for(int i=0; i<k-1; i++){
            curr=curr->next;
        }
        
        if(curr->next==NULL) return head;       //corner case if (n==k)
        
        Node *end=curr;                         //mark end
        curr=curr->next;                        //store next in curr
        end->next=NULL;                         //mark end->next as NULL
        
        Node*start=curr;                        //Mark start as curr
        
        while(curr->next!=NULL){                
            curr=curr->next;
        }
        
        curr->next=head;
        return start;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends