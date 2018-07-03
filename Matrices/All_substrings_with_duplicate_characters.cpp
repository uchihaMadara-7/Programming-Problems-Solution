/*
	--- Question Statement ---

	Given a string, print and count all substring which have duplicate character.
	Example : abcbc
 	output : abcb
             abcbc
             bcb
             bcbc
             cbc
             Total are: 5
*/

#include <iostream>

using namespace std;

void print(string str, int i, int n)
{
	while(i<=n)
		cout << str[i++];
	cout << endl;
}

bool haveDuplicate(string str, int i, int n)
{
	bool hash[26] = {false};

	for(int x=i;x<=n;x++)
	{
		if(hash[str[x]-'a'])
			return true;
		hash[str[x]-'a'] = true;
	}

	return false;
}

void all_duplicate_substring(string str)
{
	int size = str.size();
	int count = 0;

	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			if(j-i >= 1 && haveDuplicate(str, i, j))
			{
				print(str, i, j);
				count ++;
			}
		}
	}

	cout << "Total are: " << count << endl;
}

int main()
{
	string str;
	cin >> str;

	all_duplicate_substring(str);
	return 0;
}
