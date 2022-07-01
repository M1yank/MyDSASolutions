// { Driver Code Starts
// Initial Template for C++
/*	Reference: https://stackoverflow.com/questions/11809502/which-is-better-way-to-calculate-ncr
	Better solution is using DP


*/ 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nCr(int n, int r){
        if (r==0 || n==r) return 1;			//base case
        return nCr(n-1,r-1) + nCr(n-1,r);	//using Pascal Triangle ability.
    }
};

// { Driver Code Starts.
int main() {
    int n, r;
    cin >> n >> r;
    Solution ob;
    cout<<n<<"C"<<r<<" : ";
    cout<<ob.nCr(n,r)<<endl;
    return 0;
}
  // } Driver Code Ends