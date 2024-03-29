//https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
//{ Driver Code Starts
/*
Eg: 
					      50
					    /   \
					  /      \
					/		  \
				  20		   60
			     /	\		  /	 \
		        10  30		55	  80
			     \			     /  \
			     15            70    90


Input:
50 20 60 10 30 55 80 N 15 N N N N 70 90 N N N N N N
25
Output: 
5

*/




#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



// } Driver Code Ends


class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	int ceil=INT_MAX, floor=INT_MIN;
	
	void floorANDceil(Node* root, int k, int &floor, int &ceil){
	    while(root){
	        if(root->data == k){
	            ceil = root->data;
	            floor = root->data;
	            return;
	        }
	        
	        if(root->data < k){
	            floor = root->data;
	            root=root->right;
	        }
	        
	        else{
	            ceil = root->data;
	            root=root->left;
	        }
	        
	    }
	    return;
	}
	
	
	
    int minDiff(Node *root, int k)
    {
        //Your code here
        //find floor, find ceil, find min of abs difference, ez
        floorANDceil(root, k, floor, ceil);
        return min(abs(floor-k), abs(ceil-k));
    }
};


//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
       // getline(cin, s);

        Solution ob;
       cout << ob.minDiff(root1, k);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}

// } Driver Code Ends