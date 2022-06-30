/*
Problem Statement:
Given a rope of length n, you need to find the maximum number of pieces
you can make such that the length of every piece is in set {a, b, c} for
the given three values a, b, c.

return -1, if no such case exist.
Ex. 9, 2, 2, 2
*/


//Reference: https://stackoverflow.com/questions/63250075/find-the-maximum-number-of-pieces-a-rod-can-be-cut
int maxcut(int n, int a, int b, int c) {
    if(n==0) return 0; //base case a.
	if(n<0) return -1; //base case b.
	int r = max( maxcut(n-a,a,b,c), maxcut(n-b,a,b,c), maxcur(n-c,a,b,c)); //subproblems for all the cases
	
	if(r == -1) return -1; // boundry coundtion
	return (r+1); //to count the valid conditions and return to parent
}


