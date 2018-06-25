/*
	--- Question Statement ---

	Given three strings A, B, and C. Check if C is interleaving of A and B.
	Interleaving of A and B, contains all character of A and B and order of
	all characters in individual strings is preserved.
*/

#include <iostream>

using namespace std;

void make_0_at_match(string &ileave, string str, int n3, int n)
{
    int i = 0, index = 0;
	while(i < n && index < n3)
	{
		if(str[i] == ileave[index])
		{
			ileave[index] = '0';
			i ++;
		}

		index ++;
	}
}

bool isInterleave(string str1, string str2, string ileave, int n1, int n2, int n3)
{
	int index = 0, i = 0;

	make_0_at_match(ileave, str1, n3, n1);
	make_0_at_match(ileave, str2, n3, n2);

	for(i=0;i<n3;i++)
	{
		if(ileave[i] != '0')
			return false;
	}

	return true;
}

bool isInterleave_main(string str1, string str2, string ileave)
{
	int size1 = str1.size();
	int size2 = str2.size();
	int size3 = ileave.size();

	return isInterleave(str1, str2, ileave, size1, size2, size3)
			|| isInterleave(str2, str1, ileave, size2, size1, size3);
}

int main()
{
	string str1, str2, ileave;
	cin >> str1 >> str2 >> ileave;

	if(isInterleave_main(str1, str2, ileave))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
