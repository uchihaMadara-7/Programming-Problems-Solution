#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int i = 1;
	for(i=0;pow(i,3) <= n;i++);
	cout << "Integer cube root of " << n << " is " << i-1 << endl;
}
