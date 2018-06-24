#include <iostream>
#include <utility>

using namespace std;

int main()
{
	string str;
	cin >> str;

	pair<int,int> hash[26];

	int size = str.size();
	for(int i=0;i<size;i++)
	{
		hash[str[i] - 'a'].first ++;
		hash[str[i] - 'a'].second = i;
	}

	int low = -1, index;
	for(int i=0;i<26;i++)
	{
		if(hash[i].first == 1)
		{
			if(low > hash[i].second || low == -1)
			{
				low = hash[i].second;
				index = i;
			}
		}
	}

	if(low == -1)
		cout << low << endl;
	else
		cout << char(index+'a') << endl;
	return 0;
}
