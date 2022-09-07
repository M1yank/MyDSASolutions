//https://practice.geeksforgeeks.org/problems/articulation-point-1/1
//https://www.youtube.com/watch?v=3t3JHswP7mw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int node,int parent, vector<int> &tin, vector<int> &low, 
    vector<bool> &vis, vector<int> adj[], int &timer, vector<bool> &isArti){
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it:adj[node]){
            if(!vis[it]) {
                dfs(it, node, tin, low, vis, adj, timer, isArti);
                low[node] = min(low[it], low[node]);
                if(low[it] >= tin[node] && parent!=-1){
                    isArti[node] = true;
                }
                child++;
            } 
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
        if(parent == -1 && child > 1){
            isArti[node] = true;
        } 
    }

    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> tin(V, -1);
        vector<int> low(V, -1);
        vector<bool> vis(V, false);
        vector<bool> isArti(V, false);
        int timer = 0;
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i, -1, tin, low, vis, adj, timer, isArti);
        }
        vector<int> res;
        for(int i=0; i<V; i++){
            if(isArti[i]) res.push_back(i);
        }
        if(res.size()==0) res.push_back(-1);
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends