//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b){
        double x = (double)a.value/(double)a.weight;
        double y = (double)b.value/(double)b.weight;
        return x>y;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double res = 0;
        // Your code here
        sort(arr, arr+n, cmp);
        for(int i=0; i<n; i++){
            if( W -arr[i].weight >=0 ){
                res+=arr[i].value;
                W = W - arr[i].weight;
            }
            else{
                res = res + W*((double)arr[i].value / (double)arr[i].weight);
                break;
            }
        }
        return res;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends