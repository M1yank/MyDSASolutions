// { Driver Code Starts
// Initial Template for C++
// https://stackoverflow.com/questions/9812742/finding-the-total-number-of-set-bits-from-1-to-n

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int n){
        if (n<=1) return n;
        int p2= floor(log2(n));    //power of 2 just before n
        int sum=0;
        //x*2x-1 + F(n-2x) + (n-2x+1)
        sum+= ( p2*pow(2,p2-1)   +  n+1-pow(2,p2)  +    countBits(n-pow(2,p2))  ); //recursion  O(logn)
        //observe the pattern
        /*
        0    0 000          //for 1 to 7 1st term
        1    0 001          //for 8 t0 12 2nd term for left most bit
        2    0 010          //for 8 t0 12 remaining term
        3    0 011
        4    0 100
        5    0 101
        6    0 110
        7    0 111
        //find power of 2 less than n, lets take example 12, so floor(log2(12))=3
        
        8    1 000      <--Notice that rightmost-bits repeat themselves
        9    1 001      except now we have an extra '1' in every number!
        10   1 010      //
        11   1 011
        12   1 100
        */
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
