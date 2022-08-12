//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

#define ll int
class Solution{
    public:
    vector<ll> prevSmaller(ll n, ll arr[]){
        // code here
        // Your code here
        vector<ll> v(n,-1);
        stack<ll> s;        //to store indexes of previousgreater elements 
        s.push(0);      //put index of 1st in stack
        for(ll i=1; i<n; i++){
            while( s.empty()==false && arr[s.top()] >= arr[i] )
                s.pop();
            v[i] = s.empty()? -1 : s.top();
            s.push(i);
        }
        return v;
    }
    
    
    vector<ll> nextSmaller(ll arr[], ll n) 
    { 
        // Your code goes here
        vector<ll> res(n,n);
        stack<ll> s;
        s.push(n-1);
        for(ll i=n-2; i>=0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            res[i] = s.empty()? n : s.top();
            s.push(i);
        }
        return res;
    }
    
    int maxHist(int arr[], int n)
    {
        // Your code here
            // Your code here
        vector<ll> ps=prevSmaller(n, arr);
        vector<ll> ns=nextSmaller(arr, n);
        ll res=0;
        for(ll i=0; i<n; i++){
        	ll area = (ns[i]-ps[i]-1) * arr[i];
			res=max(res,area);
		}
        return res;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int result = maxHist(M[0], m);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j]==1)
                    M[i][j]+=M[i-1][j];
            }
            result=max(result, maxHist(M[i],m));
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends