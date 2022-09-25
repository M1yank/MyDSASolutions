#include <bits/stdc++.h>
using namespace std;
/*
https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
T.C.: O(8^(N^2))
S.C.: O(N^2)

*/
#define N 8

class knight
{
	public:
	
	int isSafe(int x, int y, int sol[N][N]){
		return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
	}
	
	void printSolution(int sol[N][N])
	{
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++)
				cout << " " << setw(2) << sol[x][y] << " ";
			cout << endl;
		}
	}
	
	int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[8], int yMove[8])
	{
		int k, next_x, next_y;
		if (movei == N * N)
			return 1;
			
		for (k = 0; k < 8; k++) {
			next_x = x + xMove[k];
			next_y = y + yMove[k];
			if (isSafe(next_x, next_y, sol)) {
				sol[next_x][next_y] = movei;
				if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove)) return 1;
				else sol[next_x][next_y] = -1;	//backtrack
			}
		}
		return 0;
	}
};

int main()
{
	int sol[N][N];
	
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++) 
			sol[x][y] = -1;

	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	sol[0][0]= 0;
	knight obj;
	if(!obj.solveKTUtil(0, 0, 1, sol, xMove, yMove)) cout<<"No solution"<<endl;
	else obj.printSolution(sol);
	return 0;
}

