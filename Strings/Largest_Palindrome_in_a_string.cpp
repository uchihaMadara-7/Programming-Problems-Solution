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

string LargestPalindrome(string str)
{
	int length = str.size();
	int lastindex = 0, max = 0;
	string large = "No palindrome found!!";
	for(int i=0;i<length;i++)
	{
		for(int j=length-1;j>=i;j--)
		{
			if(isPalindrome(str, i, j) && j > lastindex)
			{
				if(j - i >= 2)
				{
					if(j-i+1 > max)
					{
						max = j-i+1;
						large = str.substr(i, max);
					}
					lastindex = j;
				}
			}
		}
	}

	return large;
}

int main()
{
	string str;
	cin >> str;

	string large = LargestPalindrome(str);
	cout << large << endl;

	return 0;
}
