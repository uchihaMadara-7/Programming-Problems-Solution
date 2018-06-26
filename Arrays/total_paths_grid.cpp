/*
	--- Question Statment ---
	
	Find all the number of paths that are possible to reach from [m,n] to reach [0,0]. The only way to move is to go either left
	or down. 
	Example : n = 2, n = 2
	output: 6
*/

#include <iostream>

using namespace std;

long long int factorial(int n)
{
	long long int fact = 1;
	for(int i=2;i<=n;i++)
		fact *= i;
	return fact;
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << "Total ways are: " << factorial(n+m+2)/(factorial(n+1)*factorial(m+1)) << endl;
	return 0;
}
