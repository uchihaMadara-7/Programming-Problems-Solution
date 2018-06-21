#include <iostream>

using namespace std;

int paths(int row, int col)
{
	if(row == 0 && col == 0)
		return 1;
	int a = 0;
	int b = 0;

	if(row != 0)
		a = paths(row-1, col);
	if(col != 0)
		b = paths(row, col-1);

	return a + b;
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << paths(n, m);

	return 0;
}