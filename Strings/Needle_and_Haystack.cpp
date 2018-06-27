/*
	--- Question Statement ---

	locate a substring(needle) in a string (haystack).
	returns the index of first occurence of needle in haystack, or -1 if
	needle is not part of a haystack. Return -1 if both or either are empty.
*/

#include <iostream>

using namespace std;

int strStr(string needle, string haystack)
{
	int size1 = needle.size();
	int size2 = haystack.size();

	if(size1 == 0 || size2 == 0)
		return -1;

	for(int i=0;i<size2-size1+1;i++)
	{
		int count = 0;
		for(int j=0;j<size1;j++)
		{
			if(needle[j] == haystack[i+j])
			{
				count ++;
			}
		}

		if(count == size1)
			return i;
	}

	return -1;
}

int main()
{
	string str, substr;
	cin >> str >> substr;

	cout << strStr(substr, str) << endl;
	return 0;
}