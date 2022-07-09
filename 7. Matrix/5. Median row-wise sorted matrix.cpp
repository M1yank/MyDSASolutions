// { Driver Code Starts
//Initial template for C++
//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/
//Time Complexity: 	O( R * log(max-min) * log(c) )  
//				 :	O( R * 32 * log(c) )	ceiling(max-min)=2^32



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &M, int r, int c){
        
        //compute min max
        int min = M[0][0], max = M[0][c-1];
        for(int i=1; i<r; i++){
            if(M[i][1]<min) min=M[i][1];
            if(M[i][c-1]>max) max=M[i][c-1];
        }
        
        //find median position
        int medpos=(r*c+1)/2;
        
        //binary search
        while(min<max){
            int mid = (min+max)/2;
            int count = 0;  //elements smaller than element at mid index
            for(int i=0; i<r; i++)
                count += upper_bound(M[i].begin(), M[i].end(), mid) - M[i].begin();		
				//binary search in each row with column length c , i.e, T.C = O( log(c) )
            
			if(count<medpos)   min=mid+1;   //binary search
            else    max=mid;
            
        }
        
        return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends