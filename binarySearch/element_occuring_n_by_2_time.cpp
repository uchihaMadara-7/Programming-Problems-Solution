#include <iostream>

using namespace std;

int first_occurence(int *array, int low, int high, int key)
{
	if(high < low)
		return -1;
	int mid = low + (high-low)/2;

	if((mid == 0 || key > array[mid-1]) && key == array[mid])
		return mid;

	if(key > array[mid])
		return first_occurence(array, mid+1, high, key);
	return first_occurence(array, low, mid-1, key);
}

int last_occurence(int *array, int low, int high, int key)
{
	if(high < low)
		return -1;
	int mid = low + (high-low)/2;

	if((mid == high || key < array[mid+1]) && key == array[mid])
		return mid;

	if(key < array[mid])
		return last_occurence(array, low, mid-1, key);
	return last_occurence(array, mid+1, high, key);
}

int frequency_binary(int *array, int n, int key)
{
	int first = first_occurence(array, 0, n-1, key);
	int last = last_occurence(array, 0, n-1, key);
	return last - first + 1;
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];

	for(int i=0;i<n;i++)
		cin >> array[i];

	int key = array[n/2];

	cout << "Key = " << key << " occured = " 
             << frequency_binary(array, n, key) << " times " << endl;
	return 0;
}
