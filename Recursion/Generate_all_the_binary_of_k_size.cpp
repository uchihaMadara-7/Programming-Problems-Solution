/*
	--- Question Statement ---

	Generate all the binary digits in a string of size n or k. 
	Example: n = 3 
	output:	000
			100
			010
			110
			001
			101
			011
			111 
*/

#include <iostream>

using namespace std;

void generate(int n, string str)
{
	if(n == -1)
    {
		cout << str << endl;
        return;
    }

	str[n] = '0';
	generate(n-1, str);

    str[n] = '1';
    generate(n-1, str);
}

int main()
{
	int n;
	cin >> n;

	char str[100];
	str[n] = '\0';
	generate(n-1, str);
}
