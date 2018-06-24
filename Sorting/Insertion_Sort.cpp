#include <iostream>

using namespace std;

void InsertionSort(int *array, int n)
{
	for(int i=1;i<n;i++)
	{
		int key = array[i];
		int j = i-1;

		while(j >= 0 && array[j] > key)
		{
			array[j+1] = array[j];
			j--;
		}

		array[j+1] = key;
	}
}

int main()
{
	//2 3 1 5 4 9 8 6 7 9
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	InsertionSort(array, n);

	for(int i=0;i<n;i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}
