//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
/*
https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 

Eg:
Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-

Input: str = "A*(B+C)/D"
Output: ABC+*D/
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int prec(char c){
        if(c=='^')                  return 3;
        else if(c=='*' || c=='/')   return 2;
        else if(c=='+' || c=='-')   return 1;
        else                        return -1;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string res;
        for(int i=0; i<s.length(); i++){
            char c=s[i];
            
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                res += c;
            
            else if(c=='(')
                st.push('(');
            
            else if(c==')'){
                while (st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else{
                while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                    //if (c == '^' && st.top() == '^')
                    //    break;
                    //else {
                        res += st.top();
                        st.pop();
                    //}
                }
                st.push(c);
            }
        }
        
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends