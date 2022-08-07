//{ Driver Code Starts
/*
https://www.geeksforgeeks.org/previous-greater-element/
https://www.youtube.com/watch?v=_RtghJnM1Qo&list=PLUcsbZa0qzu3yNzzAxgvSgRobdUUJvz7p&index=42
Given an array of distinct elements, find previous greater 
element for every element. If previous greater element does not exist, print -1.
Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
Output :         -1, 10, 4, -1, -1, 40, 40

Input : arr[] = {10, 20, 30, 40}
Output :        -1, -1, -1, -1

Input : arr[] = {40, 30, 20, 10}
Output :        -1, 40, 30, 20
*/
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> previousGreater(int arr[], int n)
    {
        // Your code here
        vector<int> v(n,-1);
        stack<int> s;        //to store indexes of previousgreater elements 
        s.push(arr[0]);           //put index of 1st in stack
        for(int i=1; i<n; i++){
            while( s.empty()==false && s.top() <= arr[i] )
                s.pop();
            v[i] = s.empty()? -1 : s.top();
            s.push(arr[i]);
        }
        return v;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.previousGreater(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends