/*
	--- Question Statement ---
	
	Given a number n, print all the factors of the number in pairs under square root complexity.
	Example : n = 16
	output : (1,16) (2,8) (4,4)
*/

#include <iostream>
#include <cmath>

using namespace std;

void pairFactors(int n)
{
	int root = sqrt(n);
	for(int i=1;i<=root;i++)
	{
		if(n % i == 0)
			cout << "(" <<i << "," << n/i << ")"<<endl;
	}
}

int main()
{
	int n;
	cin >> n;
	pairFactors(n);
	return 0;
}
