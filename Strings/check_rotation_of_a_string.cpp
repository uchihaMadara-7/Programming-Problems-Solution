#include <iostream>
#include <vector>

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

	string rotated;
	cin >> rotated;

	int rotated_size = rotated.size();
	vector<int> index;
	for(int i=0;i<rotated_size;i++)
		if(rotated[i] == str[0])
			index.push_back(i);

	int size = index.size() - 1;
	while(!index.empty())
	{
		int indice = index[size--];
		string str1 = rotated;
		reverse(str1, 0, indice - 1);
		reverse(str1, indice, str1.size()-1);
		reverse(str1, 0, str1.size()-1);

		cout << str1 << endl;

		if(str == str1)
		{
			cout << "Yes";
			return 0;
		}

		index.pop_back();
	}

	cout << "No";
}
