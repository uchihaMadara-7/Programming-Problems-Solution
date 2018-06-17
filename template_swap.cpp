#include <iostream>

using namespace std;

template <class S>

S swaps(S &a, S &b)
{
	S c = a;
	a = b;
	b = c;
}

int main()
{
	char c1 = 'a';
	char c2 = 'b';
	int i1 = 7;
	int i2 = 17;
	swaps(c1, c2);
	swaps(i1, i2);
	cout << c1 <<" "<< c2 << " " << i1 << " " << i2 <<endl;
}
