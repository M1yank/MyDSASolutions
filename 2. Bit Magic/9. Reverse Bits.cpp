// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/reverse-bits3556/1/
//https://www.youtube.com/watch?v=maVlQElsS5A
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        long long res = 0;
        for(int i=0; i<32; i++){
            res<<=1;
            res|=(X&1);
            X>>=1;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}  // } Driver Code Ends
