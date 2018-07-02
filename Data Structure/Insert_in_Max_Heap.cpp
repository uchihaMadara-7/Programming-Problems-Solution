#include <iostream>

using namespace std;

void max_heapify(int array[], int parent, int size)
{
	int left = 2 * parent;
	int right = left + 1;
	int largest = parent;

	if(left <= size && array[left] > array[largest])
		largest = left;

	if(right <= size && array[right] > array[largest])
		largest = right;

	if(largest != parent)
	{
		swap(array[parent], array[largest]);
		max_heapify(array, largest, size);
	}
}

void build_max_heap(int array[], int n)
{
	for(int i=n/2;i>=1;i--)
		max_heapify(array, i, n);
}

int insert_max_heap(int array[], int n, int element)
{
	int child = n + 1;
	array[child] = element;

	int parent = child/2;
	while(parent >= 1)
	{
		if(array[parent] < array[child])
			swap(array[parent], array[child]);
		else
			break;

		child = parent;
		parent = child/2;
	}

	return n + 1;
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n+10];
	for(int i=1;i<=n;i++)
		cin >> array[i];

	build_max_heap(array, n);

	n = insert_max_heap(array, n, 9);

	for(int i=1;i<=n;i++)
		cout << array[i] << " ";
}
