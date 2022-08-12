// { Driver Code Starts
// Initial Template for C++
//https://practice.geeksforgeeks.org/contest/interview-series-60/problems/#
/*
Given an array of positive and negative integers. You have to make the array beautiful.
An array is beautiful if two adjacent integers, arr[i] and arr[i+1] have the same sign.
And you can do the following operation any number of times until the array becomes
beautiful.
If two adjacent integers have different signs, remove them.
Return the beautiful array after performing the above operation.
Note: An empty array is also a beautiful array. There can be many adjacent integers
with different signs. So remove adjacent integers with different signs from left to
right

Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.

Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty. 


Input: 2 1 -4 3 -5 2 6 -3
Output: 2 2

*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        
        stack<int> s;
        for(int i=0; i<arr.size(); i++){
            if(s.size()==0) s.push(arr[i]);
            else{
                if(arr[i]>=0 && s.top()>=0 || arr[i]<0 && s.top()<0)
                    s.push(arr[i]);
                else
                    s.pop();
            }
        }
        
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}  // } Driver Code Ends