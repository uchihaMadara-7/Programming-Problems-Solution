#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;

	int *arrival = new int[n];
	int *departure = new int[n];

	for(int i=0;i<n;i++)
		cin >> arrival[i];

	for(int i=0;i<n;i++)
		cin >> departure[i];

	sort(arrival, arrival+n);
	sort(departure, departure+n);

	int i = 1;
	int j = 0;
	int rooms;
	cin >> rooms;

	rooms --;
	while(i< n && j < n)
	{
		if(arrival[i] < departure[j])
		{
			if(rooms <= 0)
			{
				cout << "No rooms available" << endl;
				break;
			}
			rooms --;
			i++;
		}
		else if(departure[j] < arrival[i])
		{
			rooms ++;
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}

	cout << "Every one accomodate successfully!!" << endl;
	return 0;
}
