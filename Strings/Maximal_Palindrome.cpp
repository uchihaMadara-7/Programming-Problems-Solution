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

void MaximalPalindrome(string str)
{
	int length = str.size();
	int lastindex = 0;
	for(int i=0;i<length;i++)
	{
		for(int j=length-1;j>=i;j--)
		{
			if(isPalindrome(str, i, j) && j > lastindex)
			{
				if(j - i >= 2)
				{
					print(str, i, j);
					lastindex = j;
				}
			}
		}
	}
}

int main()
{
	string str;
	cin >> str;

	MaximalPalindrome(str);

	return 0;
}
