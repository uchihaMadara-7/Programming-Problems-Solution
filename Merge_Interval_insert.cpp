#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int,int>> interval;
	//pair<int,int> *interval = new pair<int,int>[n];

	int x, y;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		interval.push_back(make_pair(x, y));
	}

	cin >> x >> y;

	if(y < interval[0].first)
	{
		interval.insert(interval.begin(), make_pair(x, y));
	}

	else if(x > interval[n-1].second)
	{
		interval.push_back(make_pair(x, y));
	}

	else
	{
		bool flag1 = false, flag2 = false;
		int firstIndex = -1, lastIndex = -1;
		for(int i=0;i<n;i++)
		{
			if(x >= interval[i].first && x <= interval[i].second)
			{
				firstIndex = i;
				flag1 = true;
				if(flag2)
					break;
			}

			if(y >= interval[i].first && y <= interval[i].second)
			{
				lastIndex = i;
				flag2 = true;
				if(flag1)
					break;
			}
		}

		if(firstIndex == -1 && lastIndex == -1)
		{
			if(x < interval[0].first && y > interval[n-1].second)
			{	
				interval.erase(interval.begin(), interval.end());
				interval.push_back(make_pair(x, y));
			}
			else
			{
				/* 3
				1 2
				4 5
				7 8
				3 6 */
				flag1 = false, flag2 = false;
				for(int i=0;i<n-1;i++)
				{
					if(x > interval[i].second && x < interval[i+1].first)
					{
						firstIndex = i;
						flag1 = true;
						if(flag2)
							break;
					}

					if(y > interval[i].second && y < interval[i+1].first)
					{
						lastIndex = i;
						flag2 = true;
						if(flag1)
							break;
					}
				}

				if(firstIndex == lastIndex)
				{
					interval.insert(interval.begin() + firstIndex, make_pair(x, y));
				}
				else
				{
					interval.erase(interval.begin() + firstIndex + 1, interval.begin() + lastIndex + 1);
					interval.insert(interval.begin() + firstIndex + 1, make_pair(x, y));
				}
			}
		}

		else if(firstIndex == -1 && lastIndex != -1)
		{
			int lastElement = interval[lastIndex].second;
			interval.erase(interval.begin(), interval.begin()+lastIndex+1);
			interval.insert(interval.begin(), make_pair(x, lastElement));
		}

		else if(firstIndex != -1 && lastIndex == -1)
		{
			int firstElement = interval[firstIndex].first;
			interval.erase(interval.begin()+firstIndex, interval.end());
			interval.push_back(make_pair(firstElement, y));
		}

		else
		{
			int firstElement = interval[firstIndex].first;
			int lastElement = interval[lastIndex].second;
			interval.erase(interval.begin() + firstIndex, interval.begin() + lastIndex + 1);
			interval.insert(interval.begin() + firstIndex, make_pair(firstElement, lastElement));
		}
	}

	int size = interval.size();
	cout << endl << endl;
	for(int i=0;i<size;i++)
		cout << interval[i].first << " " << interval[i].second << endl;

	return 0;
}
