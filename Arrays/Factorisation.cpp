#include <iostream>
#include <cmath>

using namespace std;

void factorisation(int n)
{
	if(n == 1)
	{
		cout << n << endl;
		return;
	}

	int p = 2;
	while(n > 1)
	{
		int count = 0;
		while(n % p == 0)
		{
			count ++;
			n = n/p;
		}

		if(count > 0)
			cout << p << "(" << count << ")"<<endl;
		p++;
	}
}

int main()
{
	int n;
	cin >> n;
	factorisation(n);
	return 0;
}
