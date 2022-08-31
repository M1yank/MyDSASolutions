//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// T.C: O(V+E)
// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFSrec(vector<int> adj[], int node, vector<bool> &vis, vector<int> &res){
        res.push_back(node);
        vis[node] = true;
        for(auto it:adj[node]){
            if(!vis[it]) DFSrec(adj, it, vis, res);
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        vector<int> res;
        DFSrec(adj, 0, vis, res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends