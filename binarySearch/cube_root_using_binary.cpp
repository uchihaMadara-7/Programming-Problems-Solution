#include <iostream>
#include <cmath>

using namespace std;

int cubeRoot_binary(int low, int high, int n)
{
	if(high < low)
		return -1;

	int mid = low + (high - low)/2;

	if(pow(mid,3) == n || (pow(mid, 3) < n && pow(mid+1, 3) > n))
		return mid;

	if(pow(mid,3) > n)
		return cubeRoot_binary(low, mid-1, n);
	return cubeRoot_binary(mid+1, high, n);
}

int main()
{
	int n;
	cin >> n;

	cout << "Integer cube root is " << cubeRoot_binary(0, n, n) << endl;
	return 0;
}
