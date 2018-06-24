#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	int xors = 0;
	for(int i=0;i<n;i++)
		xors ^= array[i];

	cout << xors << endl;
	return 0;
}
