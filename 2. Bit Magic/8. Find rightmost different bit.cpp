// { Driver Code Starts
//Initial Template for C++
//https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1/?track=PG-BitMagic&batchId=457#

#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        if(m==n) return -1;
        int XOR = m^n, res=1;
        int setbit=XOR& (~(XOR-1)); /*example 11, 9
                                    xor 11 = 1011
                                         9 = 1001
                                        __________
                                       xor = 0010   = 2
                                    xor -1 = 0001   = 1
                                    
                                ~(xor - 1) = 1110
                                       xor = 0010   = 2
                                       ___________
                        xor &   ~(xor - 1) = 0010
                                    */
        while((setbit & 1)!=1){         //find last set bit position
                setbit=setbit>>1;
                res++;
            }
        return res;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
}   // } Driver Code Ends
