// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
        unordered_set<int> s(arr, arr+n);
      
        int res=1;                              
        int temp=0;                             //length of temporary subsequence
      
        for(int i=0; i<n; i++){
            if(s.find(arr[i]-1)==s.end()){      //run if previous element is not present, which means that this is starting of a new subsequence 
                temp=1;                         //start the sequence
                while(s.find(arr[i]+temp)!=s.end()) temp++; //increase the length of subsequence if next element is present
            }
            res=max(res, temp);                 //update res
        }
        return res;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends