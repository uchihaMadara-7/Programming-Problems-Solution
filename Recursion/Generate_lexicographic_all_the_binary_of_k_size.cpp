/*
	--- Question Statement ---

	Generate all the binary digits in a string of size n or k. The strings should be 
	printed in lexicographical order. 
	Example: n = 3 
	output:	000
			001
			010
			011
			100
			101
			110
			111 
*/

#include <iostream>
#define MAX 100

using namespace std;

void generate(string str, int n, int size)
{
	if(n == size )
	{
		cout << str << endl;
		return;
	}

	str[n] = '0';
	generate(str, n+1, size);
	str[n] = '1';
	generate(str, n+1, size);
}

int main()
{
	char str[MAX];
	int n;
	cin >> n;

	str[n] = '\0';

	generate(str, 0, n);
}
