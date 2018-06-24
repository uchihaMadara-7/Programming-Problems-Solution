#include <iostream>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

    str += ' ';
	int count = 0;
	int size = str.size();
	for(int i=0;str[i];i++)
	{
		if(str[i] == ' ' && i != 0 && str[i-1] != ' ')
			count ++;
	}

	cout << count << endl;
	return 0;
}
