#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int a = 0;
	int max = INT_MIN, max1 = INT_MIN, max2 = INT_MIN;
	while(a != -1)
	{
		cin >> a;
		if(max <= a)
		{
			if(max != a)
			{
				max2 = max1;
				max1 = max;
			}
			max = a;
		}
		else if(max1 <= a)
		{
			if(max1 != a)
				max2 = max1;
			max1 = a;
		}
		else if(max2 <= a)
			max2 = a;
	}

	cout << max2 << endl;
}
