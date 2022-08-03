//{ Driver Code Starts
//Initial template for C++
/*
Input: 
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 8,2,4,6 are the even numbers 
so they appear first and 17,15,9 are odd 
numbers that appear later.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node *eS=NULL, *eE=NULL, *oS=NULL, *oE=NULL;        //eE=even start ...
        for(Node *curr=head; curr!=NULL; curr=curr->next){
            int x=curr->data;
            if(x%2==0){
                if(eS==NULL){
                    eS=curr;
                    eE=eS;
                }
                else{
                    eE->next=curr;
                    eE=eE->next;
                }
            }
            else{
                if(oS==NULL){
                    oS=curr;
                    oE=oS;
                }
                else{
                    oE->next=curr;
                    oE=oE->next;
                }
            }
        }
        
        if(oS==NULL || eS==NULL) return head;
        eE->next=oS;
        oE->next=NULL;
        return eS;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends