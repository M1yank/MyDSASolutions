#User function Template for python3

class Solution:
    
    #Function to find a solved Sudoku. 
    
    def find_empty_space(self,sudoku):
        for r in range(9):
            for c in range(9):
                if sudoku[r][c] == 0:
                    return r,c
                    
        return None, None
    
    def guess(self,sudoku, x, i, j):
        #checks if x is valid according to current board
        #return true if valid
        
        #row check
        row = sudoku[i]
        if x in row:
            return False
            
        #column check
        col=[]
        for m in range(9):
            col.append(sudoku[m][j])
        if x in col:
            return False
            
        #3x3 block check
        row_start = (i // 3 ) * 3
        col_start = (j // 3 ) * 3
        for r in range(row_start, row_start + 3):
            for c in range(col_start, col_start + 3):
                if sudoku[r][c] == x:
                    return False
                    
        #passed all checks
        return True    
    
    def SolveSudoku(self,sudoku):
        #solve using backtracking
        #1. Find empty cell on sudoku
        i, j = self.find_empty_space(sudoku) 
        
        #no empty space
        if i is None:
            return True
            
        #found empty space and guess
        for x in range(1,10):
            if self.guess(sudoku, x, i, j):
                sudoku[i][j] = x
                
                #solve this sudoku with this guess
                if self.SolveSudoku(sudoku):
                    return True
                    
            #backtrack if not valid guess
            sudoku[i][j] = 0
            
        #if not solvable, 
        return False
        
    #Function to print grids of the Sudoku.    
    def printGrid(self,sudoku):
        for m in range(9):
            for n in range(9):
                print(sudoku[m][n],end=" ")
            
                
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t = int(input())
    while(t>0):
        grid = [[0 for i in range(9)] for j in range(9)]
        row = [int(x) for x in input().strip().split()]
        k = 0
        for i in range(9):
            for j in range(9):
                grid[i][j] = row[k]
                k+=1
                
        ob = Solution()
            
        if(ob.SolveSudoku(grid)==True):
            ob.printGrid(grid)
            print()
        else:
            print("No solution exists")
        t = t-1
# } Driver Code Ends