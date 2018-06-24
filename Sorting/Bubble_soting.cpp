#include <iostream>

using namespace std;

void bubbleSort(int *array, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			if(array[j-1] > array[j])
				swap(array[j-1], array[j]);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	bubbleSort(array, n);

	for(int i=0;i<n;i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}