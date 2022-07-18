// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    
    string reverse(string str, int low, int high){
        while(low<=high){
            swap(str[low], str[high]);
            low++;high--;
        }
        return str;
    }
    
    string reverseWords(string S) 
    { 
        int start=0;
        int n=S.length();
        if(S[0]=='.') start=1;
        for(int end=0; end<S.length(); end++){
            if(S[end]=='.'){
                S=reverse(S, start, end-1);
                start=end+1;
            }
        }
        S=reverse(S, start, n-1);
        S=reverse(S, 0, n-1);
        return S;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends