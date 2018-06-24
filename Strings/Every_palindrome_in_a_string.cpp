#include <iostream>

using namespace std;

void print(string str, int low, int high)
{
	for(int i=low;i<=high;i++)
		cout << str[i];
	cout << endl;
}

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

void allPalindrome(string str)
{
	int length = str.size();
	for(int i=0;i<length;i++)
	{
		for(int j=i;j<length;j++)
		{
			if(isPalindrome(str, i, j))
			{
				if(j - i >= 2)
					print(str, i, j);
			}
		}
	}
}

int main()
{
	string str;
	cin >> str;

	allPalindrome(str);

	return 0;
}
