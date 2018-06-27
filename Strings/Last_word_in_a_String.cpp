/*
	--- Question Statement ---

	Given a string S consist of upper/lower case alphabets and empty space
	characters, return the length of last words in the string. If the last
	word does not exist, return 0;

	Try to traverse the string only once. Example : Hello world output: 5
*/

#include <iostream>

using namespace std;

int lengthLastWords(string str)
{
	int size = str.size(), count = 0;
	for(int i=size-1;i>=0;i--)
	{
		if(str[i] != ' ')
			count ++;
		else if(i != size-1 && str[i] == ' ' && str[i+1] != ' ')
		{
			return count;
		}
	}

	return count;
}

int main()
{
	string str;
	getline(cin, str);

	cout << lengthLastWords(str) << endl;
	return 0;
}
