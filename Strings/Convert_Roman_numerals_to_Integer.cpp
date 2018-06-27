/*
	--- Question Statement ---

	Convert Roman numerals to integers from range 1 to 3999
	Example: XIV - 14 and XX - 20
*/

#include <iostream>

using namespace std;

int romanReturn(char c)
{
	switch(c)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
}

bool outOfOrder(char c1, char c2)
{
	int array[26] = {0};
	array['I'-'A'] = 0;
	array['V'-'A'] = 1;
	array['X'-'A'] = 2;
	array['L'-'A'] = 3;
	array['C'-'A'] = 4;
	array['D'-'A'] = 5;
	array['M'-'A'] = 6;

	if(array[c1-'A'] < array[c2-'A'])
		return true;
	return false;
}

int romanToInetger(string str)
{
	int number = 0;

	int size = str.size();
	for(int i=0;i<size;i++)
	{
	    if(i != size-1 && outOfOrder(str[i], str[i+1]))
	    	number = number - romanReturn(str[i]);
		else
			number = number + romanReturn(str[i]);
	}

	return number;
}

int main()
{
	string str;
	cin >> str;

	cout << romanToInetger(str) << endl;
	return 0;
}
