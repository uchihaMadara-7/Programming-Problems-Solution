#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(a == 0)
		return b;
	return gcd(b % a, a);
}

int main()
{
	int a,b;
	cin >> a >> b;
	if(gcd(a, b) == 1)
		cout << "Coprimes"<<endl;
	else
		cout << "Not Coprimes" << endl;
	return 0;
}
