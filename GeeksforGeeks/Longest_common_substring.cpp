/*
	--- Question Statement ---

Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4
The longest common substring is "abcd" and is of
length 4.

Input : X = "zxabcdezy", y = "yzabcdezx"
Output : 6
The longest common substring is "abcdez" and is of
length 6.


Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string X and 
Y respectively
The next two lines contains the 2 string X and Y.


Output:
For each test case print the length of longest  common substring of the two strings .


Constraints:
1<=T<=200
1<=size(X),size(Y)<=100


Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

*/

#include<iostream>
using namespace std;

int LongestCommonSubstring(string str1, string str2, int n, int m)
{
	int longSuffix[n+1][m+1];
	int longest = 0;

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i == 0 || j == 0)
				longSuffix[i][j] = 0;

			else if(str1[i-1] == str2[j-1])
			{
				longSuffix[i][j] = longSuffix[i-1][j-1] + 1;
				longest = max(longest, longSuffix[i][j]);
			}
			else
				longSuffix[i][j] = 0;
		}
	}

	return longest;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string str1, str2;
		cin >> str1 >> str2;

		cout << LongestCommonSubstring(str1, str2, str1.size(), str2.size()) << endl;
	}

	return 0;
}