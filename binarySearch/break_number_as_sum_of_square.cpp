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

bool isPerfect_square(int n)
{
	int squareRoot = square_root_binary(0, n ,n);

	if(pow(squareRoot, 2) == n)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;

	int root = sqrt(n);
	for(int x=1;x<=root;x++)
	{
		if(isPerfect_square(n-pow(x, 2)))
		{
			cout << "x: " << x << " y: " << sqrt(n-pow(x, 2)) 
			     << endl;
			break;
		}
	}

	return 0;
}
