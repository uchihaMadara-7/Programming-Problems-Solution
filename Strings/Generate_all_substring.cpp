#include <iostream>

using namespace std;

void print(string str, int low, int high)
{
	for(int i=low;i<=high;i++)
		cout << str[i];
	cout << endl;
}

void allSubstring(string str)
{
	int length = str.size();
	for(int i=0;i<length;i++)
	{
		for(int j=i;j<length;j++)
			print(str, i, j);
	}
}

int main()
{
	string str;
	cin >> str;

	allSubstring(str);
}
