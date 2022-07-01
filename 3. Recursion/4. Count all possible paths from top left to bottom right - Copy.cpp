// { Driver Code Starts
// Initial Template for C++
/*	Reference: https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1/#
	Time Complexity: exponential O(2^(n m))
	Better solution is using DP


*/ 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        if (m==1 || n==1) return 1;
        return (long long)(numberOfPaths(m,n-1) + numberOfPaths(m-1,n));
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends