// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int factorial(int n){
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }

    int findSmallerInRight(string str, int low, int high){
        int countRight = 0;
  
        for (int i = low + 1; i <= high; ++i)
            if (str[i] < str[low])
                ++countRight;
  
        return countRight;
    }
    
    
    int rank(string S){
        // code here
        
        unordered_map<int, int> mp;
        int n=S.length();
        for(int i = 0; i < n; i++)
            mp[S[i]]++;
        
        for(auto x : mp)
            if(x.second > 1)
                return 0;
        
        
        int mul=factorial(n);
        int rank=1;
        int countRight;
        for (int i = 0; i < n; ++i) {
            mul /= n - i;
            countRight = findSmallerInRight(S, i, n - 1);
            rank += countRight * mul;
        }
        return rank%1000003;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.rank(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends