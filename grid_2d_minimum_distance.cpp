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






