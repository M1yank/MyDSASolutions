//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int preIndex = 0;
    Node *build(int in[], int pre[], int s, int e){
        // Code here
        
        if(s>e) return nullptr;
        
        Node *root = new Node(pre[preIndex++]);
        int inIndex=0;
        for(int i=s; i<=e; i++){
            if(in[i]==root->data){
                inIndex = i;
                break;
            }
        }
        root->left = build(in, pre, s, inIndex-1);
        root->right = build(in, pre, inIndex+1, e);
        return root;
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        return build(in, pre, 0, n-1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends