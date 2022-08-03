//{ Driver Code Starts
//Initial template code for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    /*
		Method 1: 	O(N^2) :use 2 loops
		Method 2: 	Modify linked list structure and make a bool data member : bool isvisited
		Method 3: 	Modify whole linked list and store each next to temp, if any element is alredy
	            	pointing to this temp then break loop and return true
	    Method 4: 	use unordered_set<Node*> s;
	    			{
						unordered_set<Node*> s;
						for(Node *curr=head; curr!=NULL; curr=curr->next){
							if(s.find(curr) != s.end()) return true;
							s.insert(curr);
						}
						return false;
					}
		Method 5: 	Use Floyd's Cycle Detection using slow and fast pointers
					works on principal that slow and fast will always meet in a cycle if distance between 
					them is always increasing by 1; therefore they will meet when distance becomes length of cycle
	*/
	
	//Method 5 Implementation:
    bool detectLoop(Node* head)
    {
        Node *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}

// } Driver Code Ends