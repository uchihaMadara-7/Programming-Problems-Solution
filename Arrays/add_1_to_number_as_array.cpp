/*
	--- Question Statement ---
	
	Add 1 to a number represented as an array. The number can be too large to be stored in an integer.
	Example [1,2,3] output: [1,2,4]
*/

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
