#include <iostream>

using namespace std;

int nextPowerof2(int n)
{
	int bits = sizeof(int) * 8;
	int last = 0;
	for(int i= bits-1;i>=0;i--)
	{
		if(n & 1 << i)
		{
			last = i;
			break;
		}
	}

	int num = 0;
	num = num | 1 << (last+1);

	return num;
}

int main()
{
	int n;
	cin >> n;

	cout << nextPowerof2(n) << endl;
	return 0;
}
