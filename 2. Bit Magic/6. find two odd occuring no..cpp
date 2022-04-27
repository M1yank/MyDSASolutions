// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> twoOddNum(int Arr[], int N)  
    {
        // code here
        //since extra auxilary space is O(1), we cant use unordered map
        //but using unordered map:
        /*
            unordered_map<int,int> m;
            vector<int> res;
            for(int i=0;i<N;i++)
                m[arr[i]]++;
            for(auto it:m){
                if(it.second%2!=0)
                    res.push_back(it.first);
            }
            sort(res.begin(),res.end(),greater<int>());
            return res;
            
        */
        
        //using xor;    x^0=x;  x^x=0
        int xor=0;
        for(int i=0; i<N; i++){
            xor^=Arr[i];
        }
        //we get xor of a^b
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int Arr[N];
        for(int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<int>ans=ob.twoOddNum(Arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
