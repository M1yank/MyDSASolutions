//https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1
//https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    int height(Node* node){
        if(node==NULL) return 0;
        return node->height;
    }
    
    int getBalance(Node* node){
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }
    
    
    Node* leftRotate(Node *x){
        Node *y = x->right;
        Node *temp=y->left;
        
        y->left=x;
        x->right=temp;
        
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        
        return y;
    }
    
    Node* rightRotate(Node *x){
        Node *y = x->left;
        Node *temp=y->right;
        
        y->right=x;
        x->left=temp;
        
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        
        return y;
    }
    
    
    Node* insertToAVL(Node* node, int k)
    {
        //Your code here
        if(!node) return new Node(k);
        if(node->data > k) node->left = insertToAVL(node->left, k);
        else if(node->data < k) node->right = insertToAVL(node->right, k);
        else return node;
        
        
        node->height = 1 + max(height(node->left), height(node->right));
        
        int b = getBalance(node);
        
        //left left
        if(b>1 && k < node->left->data){
            return rightRotate(node);
        }
        
        //right right
        if(b<-1 && k > node->right->data){
            return leftRotate(node);
        }
        
        //left right
        if(b>1 && k > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        //right left
        if(b<-1 && k < node->right->data){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends