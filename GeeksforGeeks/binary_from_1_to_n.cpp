/*
	--- Question Statement ---

Given a number n, Write a program that generates and prints all binary numbers with decimal values 
from 1 to n.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print all binary numbers with decimal values from 1 to n in a single line.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500

Example:

Input
2
2
5

Output
1 10
1 10 11 100 101
 
** For More Input/Output Examples Use 'Expected Output' option **
Author: rajatjha


*/

#include<iostream>
#include<queue>
using  namespace std;

void generateBinary(int n)
{
	queue<string> binary;
	binary.push("1");
	int total = 1;

	while(n--)
	{
		string str = binary.front();
		binary.pop();

		cout << str << endl;

		binary.push(str+'0');
		binary.push(str+'1');
	}

	/*while(!binary.empty())
	{
		cout << binary.front() << endl;
		binary.pop();
	}*/
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		generateBinary(n);
	}

	return 0;
}