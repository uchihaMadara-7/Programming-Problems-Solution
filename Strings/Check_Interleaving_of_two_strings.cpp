/*
	--- Question Statement ---

	Given three strings A, B, and C. Check if C is interleaving of A and B.
	Interleaving of A and B, contains all character of A and B and order of
	all characters in individual strings is preserved.
*/

#include <iostream>

using namespace std;

/*
    AAY AAZ AAZAAAY     output: No
    AY WZ WZAY          output: Yes
    AY A AAY            output: Yes
    YA A AAY            output: No
    AAY AAZ AAAAZY      output: Yes
*/

bool isInterleave(string str1, string str2, string ileave, int n1, int n2, int n3)
{
	if(n3 < 0 && n1 < 0 && n2 < 0)
		return true;

	bool flag1 = false, flag2 = false;
	if(n1 >= 0 && str1[n1] == ileave[n3])
		flag1 = isInterleave(str1, str2, ileave, n1-1, n2, n3-1);
	if(n2 >= 0 && str2[n2] == ileave[n3])
		flag2 = isInterleave(str1, str2, ileave, n1, n2-1, n3-1);

	return flag1 || flag2;

}

int main()
{
	string str1, str2, ileave;
	cin >> str1 >> str2 >> ileave;

	if(isInterleave(str1, str2, ileave, str1.size()-1, str2.size()-1,
				    ileave.size()-1))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
