#include <iostream>

using namespace std;

void reverse(string &str, int low, int high)
{
	while(low < high)
	{
		char temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		low ++;
		high --;
	}
}

int main()
{
	string str;
	getline(cin, str);

	string result = "";
	int i = 0;
	int low = 0;

	reverse(str, 0, str.size()-1);
	str += ' ';

	while(str[i])
	{
		if(str[i] == ' ')
		{
			reverse(str, low, i-1);
			low = i+1;
		}
		i ++;
	}

	int size = str.size();
	int first, last;
	for(int i=0;i<size;i++)
		if(str[i] != ' ')
		{
			first = i;
			break;
		}

	for(int i=size-1;i>=0;i--)
		if(str[i] != ' ')
		{
			last = i;
			break;
		}

	str = str.substr(first, last-first+1);

	str += ' ';
	i = 0, low = 0;
	while(str[i])
	{
		if(str[i] != ' ')
			result += str[i];
		else if(str[i+1] != ' ')
			result += str[i];

		i ++;
	}

	cout << result << endl;
}
