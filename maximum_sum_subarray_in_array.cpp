#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];

	for(int i=0;i<n;i++)
		cin >> array[i];

	int currentSum = 0, maxSum = 0, segmentLength = 0, maxLength = 0;
	int lastIndex = 0, actualIndex = 0;
	for(int i=0;i<n;i++)
	{
		if(array[i] < 0)
		{
			segmentLength = i - lastIndex;
			if(i != 0)
				lastIndex = i;
			else
				lastIndex = i+1;
			if(currentSum > maxSum)
			{
				maxSum = currentSum;
				maxLength = segmentLength;
				actualIndex = i;
			}
			else if(currentSum == maxSum)
			{
				if(maxLength < segmentLength)
				{
					maxLength = segmentLength;
					actualIndex = i;
				}
			}

			currentSum = 0;
			continue;
		}

		currentSum += array[i];
	}

	segmentLength = n - lastIndex - 1;
	if(currentSum > maxSum)
	{
		maxLength = n - lastIndex - 1;
		actualIndex = n;
	}
	else if(currentSum == maxSum && maxLength < segmentLength)
	{
		maxLength = n -
        lastIndex - 1;
		actualIndex = n;
	}

	for(int i=actualIndex-maxLength; i< actualIndex;i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}
