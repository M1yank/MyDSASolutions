//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
//{ Driver Code Starts
//{ Driver Code Starts
/*
E.g.: 
Input:
4 5
0 1 2
0 2 5
1 2 1
1 3 7
2 3 1
0
Output:
0 2 3 4 
*/


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, INT_MAX);
        dis[S]=0;
        pq.push({0, S});
        while(!pq.empty()){
            auto top = pq.top();
            int parentCost = top.first;
            int parentNode = top.second;
            pq.pop();
            for(auto it: adj[parentNode]){
            	cout<<"\nit = "<<it[0]<<endl;
                int nextNode = it[0];
                int edgeCost = it[1];
                cout<<"\nnextNode = "<<nextNode<<endl;
                if( (dis[parentNode]+edgeCost)< dis[nextNode]){
                    dis[nextNode] = dis[parentNode] + edgeCost;
                    pq.push({dis[nextNode], nextNode});
                }
            }
        }
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends