/*
	--- Question Statement ---
	
	You are in an infinite 2D grid where you can move in any of the 8 directions. You are given a sequence of points
	and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it.
	You start from the first point.
	Example : [(0,0),(1,1),(2,2)] output: 2
*/

#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	pair<int,int> *coordinates = new pair<int,int>[n];

	for(int i=0;i<n;i++)
		cin >> coordinates[i].first >> coordinates[i].second;

	int distance = 0;

	for(int i=1;i<n;i++)
	{	
		int x_dist = fabs(coordinates[i].first - coordinates[i-1].first);
		int y_dist = fabs(coordinates[i].second - coordinates[i-1].second);

		if(x_dist > y_dist)
			distance += x_dist;
		else
			distance += y_dist;
	} 

	cout << "Minimum distance is: " << distance << endl;
}






