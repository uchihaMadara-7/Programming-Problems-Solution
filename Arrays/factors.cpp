/*
	--- Question Statement ---
	
	Print all the factors of a number.
*/

#include <iostream>
#include <cmath>

using namespace std;

void Factors(int n)
{
	int limit = n/2;
	for(int i=2;i<=limit;i++)
		if(n % i == 0)
			cout << i << " ";
}

int main()
{
	int n;
	cin >> n;
	Factors(n);
	return 0;
}
