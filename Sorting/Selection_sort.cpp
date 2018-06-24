#include <iostream>

using namespace std;

void SelectionSort(int *array, int n)
{
	for(int i=0;i<n;i++)
	{
		int min = i;
		for(int j=i+1;j<n;j++)
		{
			if(array[min] > array[j])
				min = j;
		}
		swap(array[min], array[i]);
	}
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	SelectionSort(array, n);

	for(int i=0;i<n;i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}