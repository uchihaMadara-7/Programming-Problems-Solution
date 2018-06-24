#include <iostream>

using namespace std;

void dec2Binary(int n)
{
	int bits = sizeof(int) * 2;
	for(int i=bits-1;i>=0;i--)
	{
		if(n & 1 << i)
			cout << "1";
		else
			cout << "0";
	}
}

int main()
{
	int n;
	cin >> n;

	dec2Binary(n);
	return 0;
}
