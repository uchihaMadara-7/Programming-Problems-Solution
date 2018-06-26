/*
	--- Question Statement ---
	
	Print all the factors of a given number under square root complexity.
*/

#include <iostream>
#include <cmath>

using namespace std;

void factors(int n, int root, int x)
{
	if(n % x == 0)
	{
		cout << x << endl;
		if(x <= root)
			factors(n, root, x+1);
		cout << n/x << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	int root = sqrt(n);
	factors(n, root, 1);
	return 0;
}
