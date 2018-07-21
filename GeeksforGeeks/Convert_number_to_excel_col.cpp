#include<iostream>
using namespace std;

string excelCol(int n)
{
	string result = "";

	while(n)
	{
		int ans = n % 26;
		if(ans == 0)
		{
			ans = 25;
			n = n/26 - 1;
		}
		else
		{
			ans = ans - 1;
			n = n/26;
		}

		result = char(ans + 'A') + result;
	}

	return result;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		cout << excelCol(n) << endl;
	}
}