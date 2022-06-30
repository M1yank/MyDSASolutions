// { Driver Code Starts
//Reference: https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1/#
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int safePos(int n, int k) {
        //recursive solution:
        return josephus(n,k)+1; //add 1 bcz of indexing
    }
    
    int josephus(int n, int k){
        if(n==1) return 0;  //Base Case: if only one person, return pos 0
        return (josephus(n-1,k)+k)%n;   
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends