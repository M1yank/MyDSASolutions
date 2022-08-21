//{ Driver Code Starts
//Initial Template for C++
//Striver: https://www.youtube.com/watch?v=2r5wLmQfD6g
/*
https://practice.geeksforgeeks.org/problems/burning-tree/1
INPUT: 
1
1 2 3 4 5 N 6 N N 7 8 N 9 10 11 N N N 12 N N N 13
8

Output:
7

*/



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    int func(unordered_map<Node*, Node*> &mp, Node* target){
        queue<Node*> q;
        q.push(target);
        int timer=0;
        unordered_map<Node*, bool> visit;
        visit[target] = true;
        while(q.size()){
            int n=q.size();
            bool flag = false;
            while(n--){
                Node* curr=q.front();
                q.pop();
                if(curr->left && !visit[curr->left]){
                    flag = true;
                    visit[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && !visit[curr->right]){
                    flag = true;
                    visit[curr->right] = true;
                    q.push(curr->right);
                }
                
                if(mp[curr] && !visit[mp[curr]]){
                    flag = true;
                    visit[mp[curr]] = true;
                    q.push(mp[curr]);
                }
            }
            if(flag) timer++;
        }
        return timer;
    }
    
    
    Node* mapParents(Node* root, unordered_map<Node*, Node*> &mp, int target){
        queue<Node*> q;
        q.push(root);
        Node *res;
        while(q.size()){
            Node* curr=q.front();
            q.pop();
            if(curr->data == target) res = curr;
            if(curr->left){
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        return res;     //return target node address
    }
    
    
    int minTime(Node* root, int target) {
        // Your code goes here
        unordered_map<Node*, Node*> mp;
        //maps parentd and returns node, where target lies
        Node* temp = mapParents(root, mp, target);  
        int res = func(mp, temp);
        return res;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends