//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Input:
6
1 2 1 3 2 3 1 1 3 		// i.e. 1 x for push(x), 2 for pop, 3 for getmin
Output: 3 2 1

Eg:
(push 5)~~(push 10)~~(push 20)~~(push 2)~~(push 6)~~(getmin)~~(push 4)~~
(  pop )~~(  pop  )~~(push 2 )~~(  pop )~~(push 1)~~(getmin)~~(  pop )~~(  pop )

15
1 5 ;1 10 ;1 20 ;1 2 ;1 6 ;3 ;1 4 ;2 ;2 ;1 2 ;2 ;1 1 ;3 ;2 ;2
Output:
2 4 6 2 1 1 2 

*/



// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
        /*returns min element from stack*/
        int getMin(){
            if(s.empty()) return -1;
            return minEle;
        }
       
        /*returns poped element from stack*/
        int pop(){
           
            //Write your code here
            if(s.empty()) return -1;
            int t=s.top();
            s.pop();
            if(t<=minEle){
                int res=minEle;
                minEle=2*minEle - t;
                return res;
            }
            else
                return t;
        }
       
        /*push element x into the stack*/
        void push(int x){
            //Write your code here
            if(s.empty()){
                minEle = x;
                s.push(x);
            }
            else if (x<=minEle){
                s.push(2*x-minEle);
                minEle = x;
            }
            else
                s.push(x);
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends