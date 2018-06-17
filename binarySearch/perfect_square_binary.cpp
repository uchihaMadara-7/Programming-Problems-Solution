#include <iostream>
#include <cmath>

using namespace std;

int square_root_binary(int low, int high, int n)
{
	if(high < low)
		return -1;

	int mid = low + (high - low)/2;

	if(pow(mid, 2) == n || (pow(mid, 2) < n && pow(mid+1, 2) > n))
		return mid;

	if(pow(mid, 2) > n)
		return square_root_binary(low, mid-1, n);
	return square_root_binary(mid+1, high, n);
}

bool isPerfect_Square(int n)
{
	int squareRoot = square_root_binary(0, n, n);

	if(pow(squareRoot, 2) == n)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;

	if(isPerfect_Square(n))
		cout << n << " is Perfect Square" << endl;
	else
		cout << n << " is not Perfect Square" << endl;
	return 0;
}
