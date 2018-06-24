#include <iostream>

using namespace std;

void StringSort(string *str, int n)
{
	int size = str[0].size();
	for(int i=size-1;i>=0;i--)
	{
		for(int x=1;x<n;x++)
		{
			int key = array[x];
			int j = x-1;

			while(j >= 0 && str[j] > key)
			{
				str[j+1] = str[j];
				j--;
			}

			str[j+1] = key;
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;

	string *str = new string[n];
	for(int i=0;i<n;i++)
		cin >> str[i];

    StringSort(str, n);

}
