/*
	--- Question Statement ---

	Write a recursive function to check if a string is palindrome. 

*/

#include <iostream>

using namespace std;

bool isPalin(string str, int low, int high)
{
	if(low >= high)
		return true;

	return str[low] == str[high] && isPalin(str, low+1, high-1);
}

int main()
{
	string str;
	cin >> str;

	cout << isPalin(str, 0, str.size()-1) << endl;
	return 0;
}
