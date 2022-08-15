/*
Time : O(n)
Space: O(h)		//h=height of tree
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;
	Node(int x){
		key=x;
		left=NULL;
		right=NULL;
	}
};

void postorder(Node *root){
	/*
	i)  left
	ii) right
	iii)root
	*/
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<(root->key)<<" ";
	}
}

/*

			  5
		   /   \
		  10    20		
		/	\	 \
	   40   30    50

*/


int main(){
	Node *root=new Node(5);
	Node *n1=new Node(10);
	Node *n2=new Node(20);
	Node *n3=new Node(40);
	Node *n4=new Node(30);
	Node *n5=new Node(50);
	
	root->left=n1;
	root->right=n2;
	n1->left=n3;
	n1->right=n4;
	n2->right=n5;
	
	postorder(root);
	
	return 0;
}