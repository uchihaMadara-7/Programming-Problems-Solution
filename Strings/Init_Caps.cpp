#include <iostream>

using namespace std;

void InitCaps(string &str)
{
	for(int i=0;str[i];i++)
	{
		if((i == 0 || str[i] == ' ') && str[i+1] != ' ')
		{
		    int index = i+1;
		    if(i == 0)
                index = i;

			if(str[index] >= 'a' && str[index] <= 'z')
				str[index] = str[index] - 'a' + 'A';
		}
	}
}

int main()
{
	string str;
	getline(cin, str);

	InitCaps(str);
	cout << str << endl;

	return 0;
}
