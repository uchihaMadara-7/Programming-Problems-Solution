#include <iostream>

using namespace std;

void SmalltoLarge(string &str)
{
	for(int i=0;str[i];i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
	}
}

int main()
{
	string str;
	getline(cin, str);

	SmalltoLarge(str);
	cout << str << endl;

	return 0;
}
