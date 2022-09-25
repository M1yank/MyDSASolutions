// { Driver Code Starts
// Initial Template for C++
//https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
/*
T.C.: O(N!)
S.C.: O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row, int col, int n, vector<vector<int>> board){
        //check row on left side
        for(int i=0; i<col; i++) 
            if(board[row][i]==1) return false;
        
        //Check upper diagonal on left side 
        for(int i=row,j=col; i>=0 && j>=0; i--,j--)
            if(board[i][j]==1) return false;
        
        //Check lower diagonal on left side 
        for(int i=row,j=col; j>=0 && i<n;i++,j--)
            if(board[i][j]==1) return false;
            
        return true;
    }
    
    void solve(int column, int n, vector<vector<int>> &board, vector<vector<int>> &res){
        if(column>=n){
            vector<int> v;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(board[i][j]==1) v.push_back(j+1);
                }
            }
            res.push_back(v);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(isSafe(i, column, n, board)){
                board[i][column]=1;
                solve(column+1, n, board, res);
                board[i][column]=0;
            }
        }
        return;
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> res;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, n, board, res);
        sort(res.begin(), res.end());
        return res;
    }
    
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends