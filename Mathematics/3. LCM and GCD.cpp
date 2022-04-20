// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    //gcd using euclidean algorithm(long division method)
    long long gcd(long long A, long long B){
        if(B==0) return A;      
        return gcd(B, A%B);
        
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        long long g = gcd(A,B);
        long long lcm = (A*B)/g;
        vector<long long> v = { lcm, g };
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
