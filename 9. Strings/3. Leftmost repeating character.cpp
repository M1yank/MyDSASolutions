// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  const int CHAR = 256;
    char firstRep (string s)
    {
        
        bool visited[CHAR];
        fill(visited, visited+ CHAR, false);
        int res=-1;
        for(int i=s.length()-1; i>=0; i--){
            if(visited[s[i]]) res=i;
            else visited[s[i]]=true;
        }
        if(res==-1) return '#';
        return s[res];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}


  // } Driver Code Ends