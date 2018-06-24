#include <iostream>

using namespace std;

bool isPower(int n)
{
	int bits = sizeof(int) * 8;
	int count = 0;
	for(int i=0;i<bits;i++)
	{
		if(n & 1 << i)
			count ++;
	}

	if(count == 1)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;

	if(isPower(n))
		cout << n << " is a power of 2" << endl;
	else
		cout << n << " is not a power of 2" << endl;
}