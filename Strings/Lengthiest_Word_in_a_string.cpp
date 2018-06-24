#include <iostream>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

    str += ' ';
	int size = str.size();
	int max = 0, count = 0;
	for(int i=0;str[i];i++)
	{
		if(str[i] == ' ')
		{
			if(max < count)
			{
				max = count;
			}
			count = 0;
		}
		else
			count ++;
	}

	cout << max << endl;
	return 0;
}
