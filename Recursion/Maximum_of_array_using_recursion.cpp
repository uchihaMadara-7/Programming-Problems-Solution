#include <iostream>
#include <climits>

using namespace std;

int max(int *array, int n)
{
	if(n == -1)
		return INT_MIN;

	int maximum = max(array, n-1);
	return array[n] > maximum ? array[n] : maximum;
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	cout << max(array, n-1) << endl;
}
