/*
	----Question Statement----

	char *repeat(char *s, int n) that creates and returns a new string that
	is made by concatenating n copies of the parameter string s. Example "hello"
	3 time is "hellohellohello".
*/

#include <iostream>
#include <string.h>

using namespace std;

char* repeat(char *s, int n)
{
	int length = strlen(s);
	char *str = new char[length*n];

	str[0] = '\0';
	while(n--)
	{
		strcat(str, s);
	}

	return str;
}

int main()
{
	char s[100];
	cin >> s;

	int n;
	cin >> n;

	cout << repeat(s, n) << endl;
	return 0;
}
