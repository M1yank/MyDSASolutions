/*
A Binary Tree is a Complete Binary Tree if all the levels are completely filled 
except possibly the last level and the last level has all keys as left as possible.
        	   18
           /       \  
         15        30  
        /  \      /  \
      40    50  100  40
     /  \   /
    8   7  9 
*/
/*
Time Complexity: O((log N)2)

Calculating the height of a tree with x nodes takes (log x) time.
Here, we are traversing through the height of the tree.
For each node, height calculation takes logarithmic time.
As the number of nodes is N, we are traversing log(N) nodes and calculating the height for each of them.
So the total complexity is (log N * log N) = (log N)2.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
    	data = x;
    	left = NULL;
    	right = NULL;
	}
};
 

int TotalNodes(Node* root)
{
	int lh=0, rh=0;
	Node *curr=root;
	while(curr!=NULL){
		lh++;
		curr=curr->left;
	}
	curr=root;
	
	while(curr!=NULL){
		rh++;
		curr=curr->right;
	}
    if (lh == rh)
        return pow(2, lh)-1;
    return 1 + TotalNodes(root->left)+ TotalNodes(root->right);
}
 
/*
        	   18
           /       \  
         15        30  
        /  \      /  \
      40    50  100  40
     /  \   / \
    8   7  9  10
*/

int main()
{
    Node* root = new Node(18);
    root->left = new Node(15);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(7);
    
    root->left->right = new Node(50);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(10);

	root->right->left = new Node(100);
	root->right->right = new Node(40);
    cout << TotalNodes(root);
    return 0;
}