/*
	--- Question Statement ---

	Find the longest common prefix in an array of String.
	Example : ["abcd","abcde","abdc"] output: ab
*/

#include <iostream>
#include <climits>

using namespace std;

string longestprefix(string *str, int n)
{
	string prefix = "";

	int minLength = INT_MAX;
	for(int i=0;i<n;i++)
	{
		int size = str[i].size();
		if(minLength > size)
		{
			minLength = size;
		}
	}

	for(int i=0;i<minLength;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(str[j][i] != str[j+1][i])
				return prefix;
		}

		prefix += str[0][i];
	}

	return prefix;
}

int main()
{
	int n;
	cin >> n;
	string *str = new string[n];

    for(int i=0;i<n;i++)
        cin >> str[i];

	string prefix = longestprefix(str, n);
	if(prefix == "")
		cout << "No common prefix"<< endl;
	else
		cout << prefix << endl;

	return 0;
}
