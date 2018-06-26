/*
	--- Question Statement ---

	Write a function to print number of steps in tower of hanoi.
	Example: n = 3
	output : 7

*/

#include <iostream>

using namespace std;

int towerHanoi(int n)
{
	static int count = 0;
	count ++;
	if(n == 1)
		return 1;

	towerHanoi(n-1);
    towerHanoi(n-1);

	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << towerHanoi(n) << endl;

	return 0;
}
