//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
/*


	0-->1--->2
		*\	 /
		  \ /				
		   3*
INPUT:
1	//test cases
4 4	//vertices edges
0 1
1 2
2 3
3 1
Output:
1


ii)

	0-->1--->2
		 \	 /
		  \ /				
		  *3*
INPUT:
1	//test cases
4 4	//vertices edges
0 1
1 2
2 3
1 3
Output:
0
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool DFS(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &recStack){
        vis[node] = true;
        recStack[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                if( DFS(i, adj, vis, recStack))  return true;
            } 
            else if (recStack[i]) return true;
        }
        recStack[node] = false;
        return false;
    }
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false);
        vector<bool> recStack(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i] && DFS(i, adj, vis, recStack)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends