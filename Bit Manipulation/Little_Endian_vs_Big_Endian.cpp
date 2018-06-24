#include <iostream>

using namespace std;

bool isLittleEndian()
{
	int n = 1;
	if(n & 1 << 0)
		return false;
	return true;
}

int main()
{
	if(isLittleEndian())
		cout << "Little Endian" << endl;
	else
		cout << "Small Endian" << endl;

	return 0;
}