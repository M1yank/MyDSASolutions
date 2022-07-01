// { Driver Code Starts
// Initial Template for C++
/*	Reference: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
	Time Complexity: Exponential O(2^N)
	Better solution is using DP


*/ 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countSubsetSum(int set[], int n, int sum)
	{
    	if (n == 0) return (sum==0)?1:0;
    	return countSubsetSum(set, n-1, sum) + countSubsetSum(set, n-1, sum-set[n - 1]);
	}
};

// { Driver Code Starts.
int main() {
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    Solution ob;
    cout<<"Count = "<<ob.countSubsetSum(set, n, sum);
    return 0;
}
  // } Driver Code Ends