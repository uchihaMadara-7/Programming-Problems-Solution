/*
	--- Question Statement ---

	Write a recursive function to reverse a string. 

*/

#include <iostream>

using namespace std;

void reverse(string &str, int low, int high)
{
	if(low >= high)
		return;

    swap(str[low], str[high]);

	reverse(str, low+1, high-1);
}

int main()
{
	string str;
	cin >> str;

	reverse(str, 0, str.size()-1);
	cout << str << endl;
	return 0;
}
