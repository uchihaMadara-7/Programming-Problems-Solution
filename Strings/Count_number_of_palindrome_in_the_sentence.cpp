/*
	--- Question ---

	Count the number of words that are palindrome in a sentence.
*/

#include <iostream>

using namespace std;

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

int TotalPalindrome(string str)
{
	int Palincount = 0;

    str += ' ';
	int count = 0;
	for(int i=0;str[i];i++)
	{
		if(str[i] == ' ')
		{
			if(i-count != i)
			{
			    //cout << i-count << " " << i-1 << endl;
				if(isPalindrome(str, i-count, i-1))
					Palincount ++;
			}

			count = 0;
		}
		else
		{
			count ++;
		}
	}

	return Palincount;
}

int main()
{
	string str;
	getline(cin, str);

    cout << TotalPalindrome(str) << endl;

	return 0;
}
