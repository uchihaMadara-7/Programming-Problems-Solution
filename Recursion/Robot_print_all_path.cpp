/*
	--- Question Statement ---

	Print all the paths of robot starting form [m,n]. The robot can only move right or
	up. 
	Example: n = 1, m = 1
	output: RU
			UR 

*/

#include <iostream>
#include <vector>

using namespace std;

vector<char> path;

void print()
{
	int size = path.size();
	for(int i=0;i<size;i++)
		cout << path[i];
	cout << endl;
}

void allPaths(int n, int m)
{
	if(n == 0 && m == 0)
	{
		print();
		return;
	}

	if(n > 0)
	{
		path.push_back('R');
		allPaths(n-1, m);
		path.pop_back();
	}

	if(m > 0)
	{
		path.push_back('U');
		allPaths(n, m-1);
		path.pop_back();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

    allPaths(n, m);
	return 0;
}
