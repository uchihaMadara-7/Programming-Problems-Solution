/*
	--- Question Statement ---
	
	Template in c++ to find square of number. template is a used to make generic methods. 
*/

#include <iostream>

using namespace std;

template <class S>

S square(S n)
{
	return n*n;
}

int main()
{
	cout << square(15) << endl;
	cout << square(15.5);
	return 0;
}
