/*
	--- Question Statement ---

	Given a string, the only operation allowed is insert characters in the
	beginning of the string. How many minimum characters are needed to be 
	inserted to make the string palindrome string.
	Example : ABC output: 2 (CBABC), AACECAAAA output: 2 (AAAACECAAAA)
*/

#include <iostream>

using namespace std;

bool isPalindrome(string str, int low, int high)
{
	while(low < high)
	{
		if(str[low] != str[high])
			return false;

		low ++;
		high --;
	}

	return true;
}

int minTomakePalindrome(string str)
{
	int size = str.size();
	int high = size - 1;

	int max_plaindrome = 0;
	while(!isPalindrome(str, 0, high))
	{
		high --;
	}

	return size - high - 1;
}

int main()
{
	string str;
	cin >> str;

	cout << minTomakePalindrome(str) << endl;
	return 0;
}