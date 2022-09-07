//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Node{
    int u,v,w;
};

class Solution
{
    //KRUSKAL O(NlogN)
	public:
	
	//comparator function according to weights
	static bool compare(Node a, Node b){
	    return a.w<b.w;
	}
	
	//find fxn : O(V)
	int find(int x, vector<int> &parent){
	    if(parent[x]==x) return x;
	    return find(parent[x], parent);
	}
	
	
	//union fxn : O(V)
	void Union(int x, int y, vector<int> &parent){
	    x=find(x, parent);
	    y=find(y, parent);
	    parent[y]=x;
	}
	
	
    int spanningTree(int V, vector<vector<int>> adj[]){
        // code here
        vector<Node> graph;
        for(int i=0; i<V; i++){
            for(auto it:adj[i])
                graph.push_back({i, it[0], it[1]});
        }
        
        sort(graph.begin(), graph.end(), compare);
        vector<int> parent(V);
        int res=0;
        for(int i=0; i<V; i++){
            parent[i]=i;        
        }
    
        for(int i=0; i<graph.size(); i++){
            int x=find(graph[i].v, parent);
            int y=find(graph[i].u, parent);
            if(x==y) continue;      //cycle found
            res+=graph[i].w;        //no cycle
            Union(x, y, parent);    
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends