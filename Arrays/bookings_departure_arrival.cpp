/*
	--- Question Statement ---
	
	A hotel manager has to process N advance of rooms for the next season. His hotel has k rooms. Bookings contain arrival
	date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand.
	Write a program that solves this problem in O(NlogN).
	Input : Arrival [ 1 3 5]
	        Depart  [ 2 6 8]
		k = 1
	output: False (No rooms available for 5)
*/

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
