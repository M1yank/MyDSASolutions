//{ Driver Code Starts
/*
https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.
*/
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        // Your code here
        vector<int> v(n,1);
        stack<int> s;        //to store indexes of previousgreater elements 
        s.push(0);           //put index of 1st in stack
        for(int i=1; i<n; i++){
            while( s.empty()==false && price[s.top()]<=price[i] )
                s.pop();
            v[i] = s.empty()? i+1: i-s.top();
            s.push(i);
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
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends