/*
	--- Question Statement ---

	Assume that there is no cycle in a binary matrix of size (n,m) ,
	find the path from (a,b) to (x,y). The path should only contains 1's and 
	without any 0 in between.

	Example :	n = 4, m = 4
				[  0 1 0 0
				   0 1 1 0
				   0 0 1 1
				   0 0 0 1 ]
				a = 0, b = 1
				x = 3, y = 3

	output: (0,1) (1,2) (2,2) (2,3) (3,3)

*/

#include <iostream>
#include <vector>
#include <utility>
#define MAX 100

using namespace std;

char matrix[MAX][MAX];
vector<pair<int,int>> coordinates;

void print()
{
	int size = coordinates.size();
	for(int i=0;i<size;i++)
		cout << "(" << coordinates[i].first << ","  << coordinates[i].second <<") ";
	cout << endl;
}

void printPath(int n, int m, int a, int b, int x, int y)
{
	if(a == x && b == y)
	{
		print();
		return;
	}

	if(a > 0 && matrix[a-1][b] == '1')
	{
		matrix[a][b] = '0';
		coordinates.push_back(make_pair(a-1,b));
		printPath(n, m, a-1, b, x, y);
		coordinates.pop_back();
		matrix[a][b] = '1';
	}

	if(b < m-1 && matrix[a][b+1] == '1')
	{
		matrix[a][b] = '0';
		coordinates.push_back(make_pair(a,b+1));
		printPath(n, m, a, b+1, x, y);
		coordinates.pop_back();
		matrix[a][b] = '1';
	}

	if(a < n-1 && matrix[a+1][b] == '1')
	{
		matrix[a][b] = '0';
		coordinates.push_back(make_pair(a+1,b));
		printPath(n, m, a+1, b, x, y);
		coordinates.pop_back();
		matrix[a][b] = '1';
	}

	if(b > 0 && matrix[a][b-1] == '1')
	{
		matrix[a][b] = '0';
		coordinates.push_back(make_pair(a,b-1));
		printPath(n, m, a, b-1, x, y);
		coordinates.pop_back();
		matrix[a][b] = '1';
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> matrix[i][j];

	int a, b;
	cin >> a >> b;

	int x, y;
	cin >> x >> y;

    coordinates.push_back(make_pair(a, b));
    printPath(n, m, a, b, x, y);

    if(coordinates.size()==1)
        cout << "No path found !!" << endl;

	return 0;
}
