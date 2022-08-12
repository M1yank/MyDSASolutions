/*
https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
Find the largest rectangular area possible in a given histogram where the largest 
rectangle can be made of a number of contiguous bars. For simplicity, assume that 
all bars have the same width and the width is 1 unit, there will be N bars height 
of each bar will be given by the array arr.


Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 
*/


/*Better Solution:
find previous smaller and next smaller element 
and after that its simply apply formula.
i.e, pre compute these arrays.
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
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
    
    
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<ll> ps=prevSmaller(n, arr);
        vector<ll> ns=nextSmaller(arr, n);
        /*cout<<"\n PrevSmaller:\n";
        for(int i=0; i<n; i++){
        	cout<<ps[i]<<" ";
		}
        cout<<"\n NextSmaller:\n";
        for(int i=0; i<n; i++){
        	cout<<ns[i]<<" ";
		}
        */
        ll res=0;
        for(ll i=0; i<n; i++){
        	ll area = (ns[i]-ps[i]-1) * arr[i];
			res=max(res,area);
		}
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends