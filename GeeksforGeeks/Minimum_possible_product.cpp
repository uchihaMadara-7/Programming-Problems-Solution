#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string getMinProduct(string input)
{
	vector<int> quantity;
	vector<int> price;

	int first = 0, i=0;
	for(i=0;input[i] != '#';i++)
	{
		if(input[i] == ' ')
		{
			quantity.push_back(stoul(input.substr(first, i-first)));
			first = i+1;
		}
	}

	quantity.push_back(stoul(input.substr(first, i-first)));

	first = i+1;
	for(i=i+1;input[i];i++)
	{
		if(input[i] == ' ')
		{
			price.push_back(stoul(input.substr(first, i-first)));
			first = i+1;
		}	
	}

	price.push_back(stoul(input.substr(first, i-first)));

	sort(quantity.begin(), quantity.end());
	sort(price.begin(), price.end(), greater<int>());

	int size = price.size(), mul = 0;

	for(int i=0;i<size;i++)
		mul += price[i] * quantity[i];

	return to_string(mul);	
}

int main()
{
	string str;
	getline(cin, str);

	cout << getMinProduct(str);

	return 0;
}