//https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1
/*
Input: n = 6
a = {1, 5, 0, 3, 4, 5}
Output: -1 1 -1 0 3 4
Explaination: Upto 3 it is easy to see 
the smaller numbers. But for 4 the smaller 
numbers are 1, 0 and 3. But among them 3 
is closest. Similary for 5 it is 4.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        // Your code here
        vector<int> v(n,-1);
        stack<int> s;        //to store indexes of previousgreater elements 
        s.push(arr[0]);      //put index of 1st in stack
        for(int i=1; i<n; i++){
            while( s.empty()==false && s.top() >= arr[i] )
                s.pop();
            v[i] = s.empty()? -1 : s.top();
            s.push(arr[i]);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends