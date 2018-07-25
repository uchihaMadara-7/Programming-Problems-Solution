#include <iostream>
#define BITS 30

using namespace std;

int inversions = 0;

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

			inversions += (n1-i);
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

int OneBits(int n)
{
	int count = 0;
	for(int i=0;i<BITS;i++)
	{
		if(n & 1 << i)
			count ++;
	}

	return count;
}

void Count(int *array, int n, int *binary)
{
	for(int i=0;i<n;i++)
	{
		binary[i] = OneBits(array[i]);
	}
}

int main()
{
	int n;
	cin >> n;

	char comma;

	int *array = new int[n];
	for(int i=0;i<n-1;i++)
		cin >> array[i] >> comma;
	cin >> array[n-1];

	int *binary = new int[n];

	Count(array, n, binary);
	MergeSort(binary, 0, n-1);

	cout << inversions << endl;

	return 0;
}
