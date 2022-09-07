//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
//{ Driver Code Starts
//T.C.: O(V+E) 
//S.C.: O(V+E) + O(V) + O(V)
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, stack<int> &s, vector<bool> &vis, vector<int> adj[]){
	    vis[node] = true;
	    for(auto it:adj[node]){
	        if(!vis[it]) dfs(it, s, vis, adj);
	    }
	    s.push(node);
	}
    
    void dfs2(int node, vector<bool> &vis, vector<int> transpose[]){
        vis[node] = true;
	    for(auto it:transpose[node]){
	        if(!vis[it]) dfs2(it, vis, transpose);
	    }
    }
    

    int kosaraju(int V, vector<int> adj[]){
        //code here
        //(i) topological sort
        vector<bool> vis(V, false);
        stack<int> s;
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i, s, vis, adj);
        }
        
        //(ii) find transpose
        vector<int> transpose[V];
        for(int i=0; i<V; i++){
            vis[i] = false; //reset vis
            for(auto it: adj[i]){
                transpose[it].push_back(i);
            }
        }
        
        //(iii) dfs with transpose
        int res=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!vis[node]) {
                dfs2(node, vis, transpose);
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends