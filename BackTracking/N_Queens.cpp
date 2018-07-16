/*
	N-Queens is a famous problem of backtracking.
	Get the theory about it online.
*/

#include <iostream>

using namespace std;

int total = 0;

void print(bool **board, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j])
				cout <<" Q ";
			else
				cout <<" _ ";
		}
		cout << endl;
	}

	cout << endl << " ------------------ " << endl;
}

bool isSafe(bool **board, int n, int row, int col)
{
	for(int i=0;i<n;i++)
		if(board[row][i])
			return false;

	for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--)
		if(board[i][j])
			return false;

	for(int i=row+1, j=col-1;i<n && j>=0;i++,j--)
		if(board[i][j])
			return false;

	return true;
}

bool nqueens(bool **board, int n, int col)
{
	if(col >= n)
	{
		print(board, n);
		total ++;
		return true;
	}

	for(int i=0;i<n;i++)
	{
		if(isSafe(board, n, i, col))
		{
			board[i][col] = true;
			//if(!nqueens(board, n, col+1))
			nqueens(board, n, col+1);
            board[i][col] = false;
		}
	}

	return false;
}

int main()
{
	int n;
	cin >> n;

	bool **board = new bool*[n];
	for(int i=0;i<n;i++)
		board[i] = new bool[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			board[i][j] = false;

    nqueens(board, n, 0);
    cout << "Total ways are : " << total << endl;
	return 0;
}
