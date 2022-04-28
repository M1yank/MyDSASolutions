// { Driver Code Starts
//Initial Template for C++
//https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1/#


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
        int xor1=0,res1=0,res2=0;		//eg 8 32
        vector<int> res;
        for(int i=0; i<N; i++){
            xor1^=Arr[i];				//xor=40
        }
        //cout<<xor1<<endl;
        //we get xor of a^b
        int setbit= xor1 & (~(xor1-1));	//finds last set bit in xor // 8
        //cout<<setbit<<endl;
        for(int i=0; i<N; i++){
            if((Arr[i]&setbit) !=0)		//8 & 32
                res1 = res1 ^ Arr[i];	//res1=8
            else
                res2 = res2 ^ Arr[i];	//rest of array i.e 32
        }
        res.push_back(res1);
        res.push_back(res2);
        sort(res.begin(),res.end(),greater<int>());
        return res;
        
        
        
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
