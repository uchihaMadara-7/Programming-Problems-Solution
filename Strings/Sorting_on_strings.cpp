#include <iostream>

using namespace std;

void StringSort(string *str, int n)
{
	int size = str[0].size();
	for(int i=size-1;i>=0;i--)
	{
		for(int x=1;x<n;x++)
		{
			string key = str[x];
			int j = x-1;

			while(j >= 0 && str[j][i] > key[i])
			{
				str[j+1] = str[j];
				j--;
			}

			str[j+1] = key;
		}
	}
}

/*
    3
    abc acb bca
*/

int main()
{
	int n;
	cin >> n;

	string *str = new string[n];
	for(int i=0;i<n;i++)
		cin >> str[i];

    StringSort(str, n);

    for(int i=0;i<n;i++)
        cout << str[i] <<" ";
    cout << endl;

    return 0;

}
