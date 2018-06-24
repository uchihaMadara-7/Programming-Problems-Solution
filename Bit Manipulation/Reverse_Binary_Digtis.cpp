#include <iostream>

using namespace std;

void reverse(int n)
{
	int no_of_bits = sizeof(int)*2;

	int num = 0;
	for(int i=0;i<no_of_bits;i++)
	{
		if(n & 1 << i)
			num = num | 1 << (no_of_bits-i-1);
	}

	cout << num << endl;
}

int main()
{
	int n;
	cin >> n;

	reverse(n);
	return 0;
}
