//{ Driver Code Starts
/*
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;
/* Link list Node */
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    

    Node *reverse(Node *head){
    	Node *curr=head;
    	Node *prev=NULL;
    	while(curr!=NULL){
    		Node *next=curr->next;
    		curr->next=prev;
    		prev=curr;
    		curr=next;
    	}
    	return prev;
    }
    
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        //step 1: find first middle
        Node *slow=head;	//slow moves 1 at a time
    	Node *fast=head;	//fast moves 2 at a time
    	while(fast->next!=NULL && fast->next->next!=NULL){ //condition slightly changed to find first middle
    		slow=slow->next;
    		fast=fast->next->next;
    	}
    	
    	//step 2: reverse slow->next
    	Node *temp=reverse(slow->next);
    	
    	//step 3: compare curr and temp and iterate until null
    	Node *curr=head;
    	while(temp){
    	    if(temp->data!=curr->data) return false;
    	    temp=temp->next;
    	    curr=curr->next;
    	}
    	return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends