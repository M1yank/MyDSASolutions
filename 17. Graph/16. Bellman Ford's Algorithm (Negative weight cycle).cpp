//https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
//{ Driver Code Starts
//T.C.: O(VE)
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>>edges){
        // Code here
        /* if after n-1 iterations still there is some 
        relaxation happens in the nth iteration then 
        that graph will definitely have negative weight cycle*/
        vector<int> dis(n, 1000000007);
        dis[0]=0;
        for(int i=0; i<n; i++){
            bool flag= false;
            for(auto it: edges){
                int u=it[0], v=it[1], wt=it[2];
                if( dis[u] + wt < dis[v]) {
                    dis[v] = dis[u] + wt;
                    flag=true;
                    
                }
            }
            if(i==n-1 && flag) return 1;
        }
        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends