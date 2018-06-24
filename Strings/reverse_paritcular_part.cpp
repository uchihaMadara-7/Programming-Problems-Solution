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
	cin >> str;

	str += ',';

	int i = 0;
	int low = 0;
	while(str[i])
	{
		if(str[i] == ',')
		{
			reverse(str, low, i-1);
			low = i+1;
		}
		i ++;
	}

	cout << str << endl;
}
