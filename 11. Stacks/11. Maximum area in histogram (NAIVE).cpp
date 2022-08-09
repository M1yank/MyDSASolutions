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


/*GENERAL IDEA:
Traverse the array and find greater at left 
and right and add arr[i] each time until 
we find smaller element and break the loop.
compare max and done
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        ll res=0;
        for(ll i=0; i<n; i++){
        	ll curr=arr[i];
        	for(ll j=i-1; j>=0; j--){
        		if(arr[j]>=arr[i]) curr+=arr[i]; 	
        		else break;
			}
			for(ll j=i+1; j<n; j++){
        		if(arr[j]>=arr[i]) curr+=arr[i]; 	
        		else break;
			}
			res=max(res, curr);
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