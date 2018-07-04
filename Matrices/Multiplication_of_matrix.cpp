/*
	--- Question Statement ---

	Write a program to multiply two matrices.
*/

#include <iostream>
#define MAX 100

int mat1[MAX][MAX];
int mat2[MAX][MAX];

using namespace std;

bool isMultPossible(int r, int c)
{
	return r == c;
}

int** multiplication(int mat1[100][100], int mat2[100][100], int r1, int n, int c2)
{
	int **mat3 = new int*[r1];
	for(int i=0;i<r1;i++)
		mat3[i] = new int[c2];

	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			mat3[i][j] = 0;
			for(int k=0;k<n;k++)
				mat3[i][j] += (mat1[i][k] * mat2[k][j]);
		}
	}

	return mat3;
}

int main()
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1;

	for(int i=0;i<r1;i++)
		for(int j=0;j<c1;j++)
			cin >> mat1[i][j];

	cin >> r2 >> c2;

	for(int i=0;i<r2;i++)
		for(int j=0;j<c2;j++)
			cin >> mat2[i][j];

	if(isMultPossible(c1, r2))
	{
		int **mat3 = multiplication(mat1, mat2, r1, c1, c2);

		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c2;j++)
				cout << mat3[i][j] << " ";
			cout << endl;
		}
	}
	else
	{
		cout << "Mulitplication not possible";
	}



}
