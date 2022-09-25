// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
/*
T.C.: O(9^(n*n))
S.C.: O(n*n)
*/
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
#define N 9
class Solution 
{
public:
    bool isValid(int row, int col, int guess, int grid[N][N]){
        //check row and col
        for(int i=0; i<N; i++){
            if(grid[row][i]==guess || grid[i][col]==guess) return false;
        }
        
        //check box
        int sx=(row/3)*3, sy=(col/3)*3;
        for(int i=sx; i<sx+3; i++){
            for(int j=sy; j<sy+3; j++)
                if(grid[i][j]==guess) return false;
        }
        
        return true;
    }
    
    bool solve(int i, int j, int grid[N][N]){
        //end of table
        if(i==N) return true;
        
        //end of row, move to next row
        if(j==N) return solve(i+1, 0, grid);
        
        //if not empty
        if(grid[i][j]!=0) return solve(i, j+1, grid);
        
        for(int x=1; x<=N; x++){
            if(isValid(i, j, x, grid)){
                grid[i][j]=x;
                if(solve(i, j+1, grid)) return true;
            }
            grid[i][j]=0;
        }
        return false;
        
        
    }
    
    bool SolveSudoku(int grid[N][N]) { 
        return solve(0, 0, grid);
    }
    
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends