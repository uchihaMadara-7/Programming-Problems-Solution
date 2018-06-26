/*
	--- Question Statement ---

	Generate all the binary digits in a string of size n or k where no two consecutive
	one's occur in the string.

	Example: n = 3 
	output:	000
			100
			010
			001
			101
*/

#include <iostream>

using namespace std;

void generate(int n, string str, bool flag)
{
	if(n == -1)
    {
		cout << str << endl;
        return;
    }

	str[n] = '0';
	generate(n-1, str, false);

	if(!flag)
	{
    	str[n] = '1';
    	generate(n-1, str, true);
    }
}

int main()
{
	int n;
	cin >> n;

	char str[100];
	str[n] = '\0';
	generate(n-1, str, false);

	return 0;
}
