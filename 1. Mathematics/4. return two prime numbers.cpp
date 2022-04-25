// { Driver Code Starts
// Initial Template for C++
// Question: https://practice.geeksforgeeks.org/problems/return-two-prime-numbers2509/1#
/*
Given an even number N (greater than 2), return two prime numbers whose 
sum will be equal to given number. There are several combinations possible. 
Print only the pair whose minimum value is the smallest among all the minimum 
values of pairs and print the minimum element first.
NOTE: A solution will always exist, read Goldbachs conjecture. 

Example 1:

Input: N = 74
Output: 3 71
Explaination: There are several possibilities 
like 37 37. But the minimum value of this pair 
is 3 which is smallest among all possible 
minimum values of all the pairs.
Example 2:

Input: 4
Output: 2 2
Explaination: This is the only possible 
prtitioning of 4.

Expected Time Complexity: O(N*log(logN))
Expected Auxiliary Space: O(N)

Solution:
https://www.youtube.com/watch?v=V21Mn1jYsRE
*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool prime(int n){
        
        if(n==2 || n==3) return true;
        if(n%2==0 || n%3==0) return false;
        for(int i=5; i*i<=n; i=i+6){
            if(n%i==0 || n%(i+2)==0) return false;
        }
        return true;
    }
    
    vector<int> primeDivision(int n){
        vector<int> v;
        for(int i=2; i<n; i++){
            if(prime(i) && prime(n-i)){
                v.push_back(i);
                v.push_back(n-i);
                //return v;
            }
        }   
        return v;
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
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends
