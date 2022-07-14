// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        //replace every 0 with -1
        //than find largest subarray with 0 sum
        
        for(int i=0; i<N; i++){
            if(arr[i]==0)   arr[i]=-1;
        }
        
        unordered_map<int,int> m;
        int pre_sum=0, res =0;
        int SUM=0;                  //longest subarray with given SUM variation
        for(int i=0; i<N; i++){
            pre_sum+=arr[i];
            if(pre_sum==SUM) res= i+1;
            if(m.find(pre_sum)==m.end()) m.insert({pre_sum, i});            //if prefix sum already exist, than dont insert
            if(m.find(pre_sum-SUM)!=m.end()) res=max( res, i-m[pre_sum-SUM]);
            
        }
        return res;
        
    }
};


// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends