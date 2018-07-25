#include<iostream>
#include<queue>
using namespace std;

void enqueue(queue<pair<int,int>> &cordinate, int n, int x, int y)
{
	if(x+2 < n && y+1 < n)
		cordinate.push(make_pair(x+2,y+1));
	if(x+2 < n && y-1 >= 0)
		cordinate.push(make_pair(x+2,y-1));

	if(x-2 >=0 && y+1 < n)
		cordinate.push(make_pair(x-2,y+1));
	if(x-2 >=0 && y-1 >= 0)
		cordinate.push(make_pair(x-2,y-1));

	if(x+1 < n && y+2 < n)
		cordinate.push(make_pair(x+1,y+2));
	if(x-1 >= 0 && y+2 < n)
		cordinate.push(make_pair(x-1,y+2));

	if(x+1 < n && y-2 >= 0)
		cordinate.push(make_pair(x+1,y-2));
	if(x-1 >= 0 && y-2 >= 0)
		cordinate.push(make_pair(x-1,y-2));
}

void knight(bool **array, int n, int x, int y, int a, int b, int count = 0)
{
	if(x == a && y == b)
	{
		cout << count << endl;
		return;
	}

	queue<pair<int,int>> cordinate;
	enqueue(cordinate, n, x, y);

	while(!cordinate.empty())
	{
		pair<int,int> p = cordinate.front();
		cordinate.pop();

		//cout << p.first << " " << p.second << endl;

		if(!array[p.first][p.second])
		{
			array[p.first][p.second] = true;
			knight(array, n, p.first, p.second, a, b, count+1);
			array[p.first][p.second] = false;
		}
	}
}

int minSteps(int n, int x, int y, int a, int b)
{
	bool **array = new bool*[n+1];
	for(int i=0;i<n+1;i++)
		array[i] = new bool[n+1];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			array[i][j] = false;

	knight(array, n, x, y, a, b);
	return 0;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, x, y, a, b;
		cin >> n >> x >> y >> a >> b;

		cout << minSteps(n, x, y, a, b) << endl;
	}
}