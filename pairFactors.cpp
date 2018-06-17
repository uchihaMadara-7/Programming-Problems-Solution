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
