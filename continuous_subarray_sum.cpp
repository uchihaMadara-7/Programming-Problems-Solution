#include <iostream>

using namespace std;

void contSubArray(int *array, int n, int key)
{
	int lastIndex = 0, sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += array[i];

		while(sum > key)
		{
			sum = sum - array[lastIndex];
			lastIndex ++;
		}

		if(sum == key)
                {
                        cout <<"Sum found between index: " << lastIndex << " and " << i << endl;
                        return;
                }
	}

	cout << "No subarray found!! "<<endl;
}

int main()
{
	int n;
	cin >> n;
	int *array = new int[n];

	for(int i=0;i<n;i++)
		cin >> array[i];

	int key;
	cin >> key;

	contSubArray(array, n, key);
}
