// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/power-set4302/1/#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int len=s.length();
		    vector<string> res;
		    int size = pow(2,len);                  //2^n outputs
		    for(int i=1; i<size; i++){              
		        string temp;                        
		        for(int j=0; j<len; j++){           
		            if((i & (1<<j) ) != 0  ){       
		                temp+=s[j];
		            }
		        }
		        //if(i!=0)
		        res.push_back(temp);
		    }
		    sort(res.begin(),res.end());
		    return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
