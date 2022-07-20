// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    set<string> v;      //use set to remove duplicate elements
		vector<string>find_permutation(string S)
		{
		    permute(S,0);   //call backtrack fxn
		    vector<string> res = {v.begin(),v.end()};  
		    return res;
		}
		
		void permute(string s, int l){
		    if(l==s.size()) {               //if we reach node of tree
		        v.insert(s);                //then insert that string in set v
		        return;                     //and return
		    }
		    
		    for(int i=l; i<s.size(); i++){
		        swap(s[l],s[i]);            //swap next element
		        permute(s,l+1);             //backtrack
		        swap(s[l],s[i]);            //swap to previous string to find next permutation
		    }
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends