#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	if(n == 1)
		return false;
	bool flag = true;
	int root = sqrt(n);
	for(int i=2;i<=root;i++)
	{
		if(n % i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	int n;
	cin >> n;
	if (isPrime(n))
		cout << "Number is Prime"<<endl;
	else
		cout << "Number is not Prime" << endl;
	cout << isPrime(n);
	return 0;
}
