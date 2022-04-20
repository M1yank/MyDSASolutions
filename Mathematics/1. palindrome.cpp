// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    int res=0, a=n;
		    while(n!=0){
		        int temp = n%10;
		        res = res*10 + temp ;
		        n=n/10;
		    }
		    if(a==res) return "Yes";
		    else return "No";
		        
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends
