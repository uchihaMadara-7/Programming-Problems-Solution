#include <iostream>

using namespace std;

int partition(int array[], int low, int high)
{
	int pivot = high;
	int index = low;

	while(low < high)
	{
		if(array[low] < array[pivot])
		{
			swap(array[low], array[index]);
			index ++;
		}
		low ++;
	}

	swap(array[index], array[high]);
	return index;
}

void quick_sort(int array[], int low, int high)
{
	if(low < high)
	{
		int pivot = partition(array, low ,high);
		quick_sort(array, low, pivot-1);
		quick_sort(array, pivot+1, high);
	}
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	quick_sort(array, 0, n-1);

	for(int i=0;i<n;i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}
