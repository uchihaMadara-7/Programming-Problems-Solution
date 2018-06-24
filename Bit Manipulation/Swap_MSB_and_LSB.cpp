#include <iostream>

using namespace std;

int Swap_MSB_LSB(int n)
{
	int high = sizeof(int)*2-1;
	int msb2lsb = (n & 1 << 0) << high;
	int lsb2msb = (n & 1 << high) >> high;

	n = n & ~(1 << 0);
	n = n & ~(1 << high);

	return n | msb2lsb | lsb2msb;
}

int main()
{
	int n;
	cin >> n;

	cout << Swap_MSB_LSB(n);
	return 0;
}
