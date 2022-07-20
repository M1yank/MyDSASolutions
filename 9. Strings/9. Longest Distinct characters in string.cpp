// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string str)
{
    // your code here
    int n=str.length();
    int res=0;
    vector<int> prev(256,-1);
    int i=0;
    for(int j=0; j<n; j++){
        i=max(i, prev[str[j]]+1);
        int maxEnd= j-i+1;
        res=max(res,maxEnd);
        prev[str[j]]=j;
    }
    return res;
}