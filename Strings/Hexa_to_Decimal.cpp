#include <iostream>

using namespace std;

void hexatoDecimal(string str, int n)
{
	int number;
	int hexa = 0;
	for(int i=0;i<n;i++)
	{
		if(str[i] >= 'A' && str[i] <= 'F')
			number = str[i] - 'A' + 10;
		else
			number = str[i] - '0';

		hexa = hexa * 16 + number;
	}

	cout << hexa << endl;
}

int main()
{
	string str;
	cin >> str;

	hexatoDecimal(str, str.size());
	return 0;
}