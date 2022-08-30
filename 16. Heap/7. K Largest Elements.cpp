//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    /*
	    Max Heap: O(n + k*log(n))
	    Min Heap: O(k + (n-k)*log(k))   //much better
	    */
	    // code here
	    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k);
	    for(int i=k; i<n; i++){
	        if(pq.top()<arr[i]){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    vector<int> res;
	    while(!pq.empty()){
	        res.push_back(pq.top());
	        pq.pop();
	    }
	    reverse(res.begin(), res.end());
	    return res;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends