#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];

	for(int i=0;i<n;i++)
		cin >> array[i];

	int carry = 1;
	for(int i=n-1;i>=0;i--)
	{
		array[i] += carry;
		if(array[i] > 9)
		{
			array[i] = 0;
			carry = 1;
		}
		else
			carry = 0;
	}

	if(carry)
		cout << carry << " ";

	for(int i=0;i<n;i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}
