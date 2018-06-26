/*
	--- Question Statement ---

	Generate all the binary digits in a string of size n or k where no two consecutive
	one's occur in the string. The strings should be printed in lexicographical order.

	Example: n = 3 
	output:	000
			001
			010
			100
			101 
*/

#include <iostream>
#define MAX 100

using namespace std;

void generate(string str, int n, int size, bool flag)
{
	if(n == size)
	{
		cout << str << endl;
		return;
	}

	str[n] = '0';
	generate(str, n+1, size, false);

	if(!flag)
	{
		str[n] = '1';
		generate(str, n+1, size, true);
	}
}

int main()
{
	char str[100];
	int n;
	cin >> n;

	str[n] = '\0';

	generate(str, 0, n, false);
	return 0;
}
