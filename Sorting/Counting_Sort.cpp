#include <iostream>

using namespace std;

void CountingSort(int *array, int n)
{
	int counting[100] = {0};

	for(int i=0;i<n;i++)
		counting[array[i]] ++;

	for(int i=1;i<100;i++)
		counting[i] = counting[i] + counting[i-1];

	int *output = new int[n+1];
	for(int i=n-1;i>=0;i--)
	{
		output[counting[array[i]]-1] = array[i];
		counting[array[i]] --;
	}

    for(int i=0;i<n;i++)
        array[i] = output[i];
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	CountingSort(array, n);

	for(int i=0;i<n;i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}
