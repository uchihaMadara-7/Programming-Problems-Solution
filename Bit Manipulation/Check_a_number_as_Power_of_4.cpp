#include <iostream>

using namespace std;

bool isPowerOf4(int n)
{
	int bits = 8 * sizeof(int);
	int count = 0;

	for(int i=0;i<bits;i+=2)
	{
		if((n & 1 << i) && !(n & 1 << (i+1)))
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

	if(isPowerOf4(n))
		cout << n <<" is a power of 4"<<endl;
	else
		cout << n <<" is not a power of 4"<<endl;
}
