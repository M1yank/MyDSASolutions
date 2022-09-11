//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//T.C.: O(n*n!)
	//S.C.: O(n)
        void solve(int index, string &s, vector<string> &v){
            if(index==s.length()){
                v.push_back(s);
                return;
            }
            
            for(int i=index; i<s.length(); i++){
                if(i>index && s[i]==s[i-1]) continue;   //for repeating characters
                swap(s[i], s[index]);
                solve(index+1, s, v);
                swap(s[i], s[index]);
            }
            
        }
	
	
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> res;
		    solve(0, S, res);
		    sort(res.begin(), res.end());
		    return res;
		}
};



//{ Driver Code Starts.
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