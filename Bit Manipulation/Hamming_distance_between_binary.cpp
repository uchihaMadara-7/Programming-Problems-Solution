#include <iostream>

using namespace std;

int hammingDistance(int n, int m)
{
	int bits = sizeof(int) * 8;
	int xors = n ^ m;
	int distance = 0;

	for(int i=0;i<bits;i++)
	{
		if(xors & 1 << i)
            distance ++;
	}

	return distance;
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << hammingDistance(n, m);
	return 0;
}
