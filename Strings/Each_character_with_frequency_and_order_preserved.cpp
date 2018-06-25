/*
	--- Question Statement ---

	Output string which comprises the letters followed by each time it has
	occured in the original string.

	Example : abcdabf output: a2b2c1d1f1
	          information output: i2n2f1o2r1m1a1t1
*/

#include <iostream>

using namespace std;

string encrypted(string str)
{
	int hash[26] = {0};
	string output = "";

	for(int i=0;str[i];i++)
		hash[str[i]-'a'] ++;

	for(int i=0;str[i];i++)
	{
		if(hash[str[i]-'a'] != 0)
		{
			output += str[i];
			output += char('0' + hash[str[i]-'a']);
			hash[str[i]-'a'] = 0;
		}
	}

	return output;
}

int main()
{
	string str;
	cin >> str;

	cout << encrypted(str) << endl;
	return 0;
}
