#include <iostream>

using namespace std;

void merge(int *array, int low, int mid, int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int *left = new int[n1];
	int *right = new int[n2];

	for(int i=0;i<n1;i++)
		left[i] = array[i+low];

	for(int i=0;i<n2;i++)
		right[i] = array[mid+i+1];

	int i = 0, j = 0, index = low;
	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j])
		{
			array[index] = left[i];
			index ++;
			i ++;
		}
		else
		{
			array[index] = right[j];
			index ++;
			j ++;
		}
	}

	while(i < n1)
	{
		array[index] = left[i];
		index ++;
		i ++;
	}

	while(j < n2)
	{
		array[index] = right[j];
		index ++;
		j ++;
	}
}

void MergeSort(int *array, int low, int high)
{
	if(low < high)
	{
		int mid = low + (high-low)/2;
		MergeSort(array, low, mid);
		MergeSort(array, mid+1, high);
		merge(array, low, mid, high);
	}
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	MergeSort(array, 0, n-1);

	for(int i=0;i<n;i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}
