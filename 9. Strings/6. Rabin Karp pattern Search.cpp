// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/*
The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its 
worst-case time is O(nm). Worst case of Rabin-Karp algorithm occurs when all characters 
of pattern and text are same as the hash values of all the substrings of txt[] 
match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.
*/

 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int n=txt.length(), m=pat.length();
            int q=INT_MAX;
            vector<int> res;
            int d = 256;
            int h=1;
            int t=0, p=0;   //hash value for text and pattern
            for(int i=0; i<m-1; i++)
                h=(h*d)%q;
                
            for(int i=0; i<m; i++){
                t=(t*d+txt[i])%q;
                p=(p*d+pat[i])%q;
            }
            
            for(int i=0; i<=n-m; i++){
                if(p==t){
                    bool flag=true;
                    for (int j=0; j<m; j++) {
                        if (txt[i+j] != pat[j]){
                            flag=false; 
                            break;
                        }
                    }
                    if(flag==true) res.push_back(i+1);    //add 1 bcz mentioned in question
                }
                
                if(i<n-m){
                    t=(d*(t-h*txt[i])+txt[i+m])%q;
                    if(t<0) t+=q;
                }
            }
            if(res.size()==0) res.push_back(-1);
            return res;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends