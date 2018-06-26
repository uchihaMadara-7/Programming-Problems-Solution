/*
	--- Question Statement ---
	
	Write a program to print all the prime factors of given number under square root complexity.
	Example : n = 24
	output:   2 (3)
		  3 (1)
*/

#include <iostream>
#include <cmath>

using namespace std;

void primeFactors(int n)
{
	int count = 0;
	while(n % 2 == 0)
	{
		n = n/2;
		count ++;
	}

	if(count > 0)
		cout << "2("<<count <<")"<<endl;

	int root = sqrt(n);
	for(int p=3;p<=root;p+=2)
	{
		count = 0;
		while(n % p == 0)
		{
			n = n/p;
			count ++;
		}

		if(count > 0)
		{
			cout << "(" << p << ")" << endl;
		}
	}

	if(n > 1)
		cout << n << "(1)"<<endl;
}

int main()
{
	int n;
	cin >> n;
	primeFactors(n);
	return 0;
}

